#ifndef OGS_DIAM_SGD_MESSAGE_H
#define OGS_DIAM_SGD_MESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define OGS_DIAM_SGD_APPLICATION_ID 16777313

typedef struct ogs_diam_sgd_message_s {
    uint32_t cmd_code;
    uint32_t result_code;
    uint32_t *err;
    uint32_t *exp_err;
} ogs_diam_sgd_message_t;

/* Command Codes */
#define OGS_DIAM_SGD_CMD_MO_FORWARD_SHORT_MESSAGE 8388645
#define OGS_DIAM_SGD_CMD_MT_FORWARD_SHORT_MESSAGE 8388646

/* External Variables */
extern struct dict_object *ogs_diam_sgd_application;

extern struct dict_object *ogs_diam_sgd_sc_address; 
extern struct dict_object *ogs_diam_sgd_ofr_flags; 
extern struct dict_object *ogs_diam_sgd_supported_features; 
extern struct dict_object *ogs_diam_sgd_sm_rp_ui; 
extern struct dict_object *ogs_diam_sgd_sm_delivery_outcome; 
extern struct dict_object *ogs_diam_sgd_smsmi_correlation_id;

extern struct dict_object *ogs_diam_sgd_sm_delivery_failure_cause;
extern struct dict_object *ogs_diam_sgd_external_identifier;


extern struct dict_object *ogs_diam_sgd_user_name;
extern struct dict_object *ogs_diam_sgd_mme_number_for_mt_sms;
extern struct dict_object *ogs_diam_sgd_sgsn_number;
extern struct dict_object *ogs_diam_sgd_sm_deliver_timer;
extern struct dict_object *ogs_diam_sgd_sm_delivery_start_time;
extern struct dict_object *ogs_diam_sgd_maximum_retransmission_time;
/* Function Declarations */
int ogs_diam_sgd_init(void);

#ifdef __cplusplus
}
#endif

#endif /* OGS_DIAM_SGD_MESSAGE_H */