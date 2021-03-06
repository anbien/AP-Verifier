
#ifndef AP_VERIFIER_ROUTER_H
#define AP_VERIFIER_ROUTER_H

#include <cstdint>
#include <map>
#include <vector>
#include <list>
#include "ap_verifier_utils.h"
#include "predicate_node.h"
#include "ap_node.h"
#include "ap_nodeB.h"
#include "ap_nodeV.h"
#include "ap_nodeS.h"

class Router {
public:
    const uint32_t router_id;

    // map from inport to its predicate map
    std::map< uint64_t, std::map<Json::Value, PredicateNode*>* > predicate_map;

    // map from inport to the packet header space already dealt with on this in_port
    std::map< uint64_t, bdd > dealt_bdd_map;

    // map from inport to its ap represented in bool vector;
    std::map< uint64_t, std::map<Json::Value, APNodeV*>* > ap_vec_map;

    // map from inport to its ap represented in bitset;
    std::map< uint64_t, std::map<Json::Value, APNodeB*>* > ap_bset_map;

    // map from inport to its ap represented in number set;
    std::map< uint64_t, std::map<Json::Value, APNodeS*>* > ap_nset_map;

    // constructor
    Router(uint32_t id);

    // destructor
    ~Router();

    void print_router();

    string to_string();

    void convert_to_ap(AP_TYPE type, std::vector< bdd >* ap_list);

    void print_router_ap_map(AP_TYPE type);

    void print_router_apv_map();

    void print_router_apb_map();

    void print_router_apn_map();

};
#endif //AP_VERIFIER_ROUTER_H
