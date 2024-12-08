/*siz-tel todo*/
#include "ogs-diameter-sgd.h"

#define CHECK_dict_search( _type, _criteria, _what, _result )    \
    CHECK_FCT(  fd_dict_search( fd_g_config->cnf_dict, (_type), (_criteria), (_what), (_result), ENOENT) );
#ifndef NULL
#define NULL 0
#endif

/* need to add dict commands here to search them in ogs_diam_sgd_init*/
//MO-Forward-Short-Message-Request ::= <Diameter Header: 8388645, REQ, PXY, 16777313>
//MO-Forward-Short-Message-Answer ::= <Diameter Header: 8388645, PXY, 16777313>
//MT-Forward-Short-Message-Request ::= <Diameter Header: 8388646, REQ, PXY, 16777313>
//MT-Forward-Short-Message-Answer ::= <Diameter Header: 8388646, PXY, 16777313>
struct dict_object *ogs_diam_cmd_sgd_or = NULL; //MO-Forward-Short-Message-Request 
struct dict_object *ogs_diam_cmd_sgd_oa = NULL; //MO-Forward-Short-Message-Answer
struct dict_object *ogs_diam_cmd_sgd_tr = NULL; //MT-Forward-Short-Message-Request
struct dict_object *ogs_diam_cmd_sgd_ta = NULL; //MT-Forward-Short-Message-Answer






/* need to add dict avps here to search them in ogs_diam_sgd_init*/

        // SC-Address
        // OFR-Flags
        // Supported-Features
        // SM-RP-UI
        // SM-Delivery-Outcome
        // SMSMI-Correlation-ID

struct dict_object *ogs_diam_sgd_sc_address = NULL; 
struct dict_object *ogs_diam_sgd_ofr_flags = NULL; 
struct dict_object *ogs_diam_sgd_supported_features = NULL; 
struct dict_object *ogs_diam_sgd_sm_rp_ui = NULL; 
struct dict_object *ogs_diam_sgd_sm_delivery_outcome = NULL; 
struct dict_object *ogs_diam_sgd_smsmi_correlation_id = NULL;

        // Supported-Features **dual
        // SM-Delivery-Failure-Cause
        // SM-RP-UI **dual
        // External-Identifier

struct dict_object *ogs_diam_sgd_sm_delivery_failure_cause = NULL;
struct dict_object *ogs_diam_sgd_external_identifier = NULL;


        // User-Name
        // Supported-Features **dual
        // SMSMI-Correlation-ID**dual
        // SC-Address**dual
        // SM-RP-UI**dual
        // MME-Number-for-MT-SMS
        // SGSN-Number
        // SM-Delivery-Timer
        // SM-Delivery-Start-Time
        // Maximum-Retransmission-Time


struct dict_object *ogs_diam_sgd_user_name = NULL;
struct dict_object *ogs_diam_sgd_mme_number_for_mt_sms = NULL;
struct dict_object *ogs_diam_sgd_sgsn_number = NULL;
struct dict_object *ogs_diam_sgd_sm_deliver_timer = NULL;
struct dict_object *ogs_diam_sgd_sm_delivery_start_time = NULL;
struct dict_object *ogs_diam_sgd_maximum_retransmission_time = NULL;
// struct dict_object *ogs_diam_sgd_ = NULL;

/*todo no idea wtf is this copied for s6a format*/
extern int ogs_dict_sgd_entry(char *conffile);



int ogs_diam_sgd_init(void)
{
        application_id_t id = OGS_DIAM_SGD_APPLICATION_ID;

        /*todo no idea wtf is this copied for s6a format*/
        ogs_assert(ogs_dict_sgd_entry(NULL) == 0);


        /*todo no idea wtf is this copied for s6a format*/
        CHECK_dict_search(DICT_APPLICATION, APPLICATION_BY_ID, (void *)&id, &ogs_diam_sgd_application);


        /*Commands*/

    /* dict commands to search in ogs_diam_sgd_init*/
    //MO-Forward-Short-Message-Request ::= <Diameter Header: 8388645, REQ, PXY, 16777313>
    //MO-Forward-Short-Message-Answer ::= <Diameter Header: 8388645, PXY, 16777313>
    //MT-Forward-Short-Message-Request ::= <Diameter Header: 8388646, REQ, PXY, 16777313>
    //MT-Forward-Short-Message-Answer ::= <Diameter Header: 8388646, PXY, 16777313>

// struct dict_object *ogs_diam_cmd_sgd_or = NULL; //MO-Forward-Short-Message-Request 
// struct dict_object *ogs_diam_cmd_sgd_oa = NULL; //MO-Forward-Short-Message-Answer
// struct dict_object *ogs_diam_cmd_sgd_tr = NULL; //MT-Forward-Short-Message-Request
// struct dict_object *ogs_diam_cmd_sgd_ta = NULL; //MT-Forward-Short-Message-Answer


        CHECK_dict_search(DICT_COMMAND, CMD_BY_NAME, "MO-Forward-Short-Message-Request", &ogs_diam_cmd_sgd_or);
        CHECK_dict_search(DICT_COMMAND, CMD_BY_NAME, "MO-Forward-Short-Message-Answer", &ogs_diam_cmd_sgd_oa);
        CHECK_dict_search(DICT_COMMAND, CMD_BY_NAME, "MT-Forward-Short-Message-Request", &ogs_diam_cmd_sgd_tr);
        CHECK_dict_search(DICT_COMMAND, CMD_BY_NAME, "MT-Forward-Short-Message-Answer", &ogs_diam_cmd_sgd_ta);



    // struct dict_object *ogs_diam_sgd_sc_address = NULL; 
    // struct dict_object *ogs_diam_sgd_ofr_flags = NULL; 
    // struct dict_object *ogs_diam_sgd_supported_features = NULL; 
    // struct dict_object *ogs_diam_sgd_sm_rp_ui = NULL; 
    // struct dict_object *ogs_diam_sgd_sm_delivery_outcome = NULL; 
    // struct dict_object *ogs_diam_sgd_smsmi_correlation_id = NULL;

    // struct dict_object *ogs_diam_sgd_sm_delivery_failure_cause = NULL;
    // struct dict_object *ogs_diam_sgd_sm_rp_ui = NULL;
    // struct dict_object *ogs_diam_sgd_external_identifier = NULL;

    // struct dict_object *ogs_diam_sgd_user_name = NULL;
    // struct dict_object *ogs_diam_sgd_mme_number_for_mt_sms = NULL;
    // struct dict_object *ogs_diam_sgd_sgsn_number = NULL;
    // struct dict_object *ogs_diam_sgd_sm_deliver_timer = NULL;
    // struct dict_object *ogs_diam_sgd_sm_delivery_start_time = NULL;
    // struct dict_object *ogs_diam_sgd_maximum_retransmission_time = NULL;

        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SC-Address", &ogs_diam_sgd_sc_address);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "OFR-Flags", &ogs_diam_sgd_ofr_flags);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "Supported-Features", &ogs_diam_sgd_supported_features);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SM-RP-UI", &ogs_diam_sgd_sm_rp_ui);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SM-Delivery-Outcome", &ogs_diam_sgd_sm_delivery_outcome);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SMSMI-Correlation-ID", &ogs_diam_sgd_smsmi_correlation_id);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SM-Delivery-Failure-Cause", &ogs_diam_sgd_sm_delivery_failure_cause);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "External-Identifier", &ogs_diam_sgd_external_identifier);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "User-Name", &ogs_diam_sgd_user_name);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "MME-Number-for-MT-SMS", &ogs_diam_sgd_mme_number_for_mt_sms);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SGSN-Number", &ogs_diam_sgd_sgsn_number);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SM-Delivery-Timer", &ogs_diam_sgd_sm_deliver_timer);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "SM-Delivery-Start-Time", &ogs_diam_sgd_sm_delivery_start_time);
        CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "Maximum-Retransmission-Time", &ogs_diam_sgd_maximum_retransmission_time);
        // CHECK_dict_search(DICT_AVP, AVP_BY_NAME_ALL_VENDORS, "", &);

        return 0;
}

