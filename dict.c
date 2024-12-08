/*
  Copyright siz-tel PRIVATE CODE,
  If you are reading this and you are not a part of siz-tel
  SO واگذارت میکنم به دو دست بریده ی ابلفضل
*/
#include <freeDiameter/extension.h>

#include "ogs-diameter-sgd.h"

/* The content of this file follows the same structure as dict_base_proto.c */

#define CHECK_dict_new( _type, _data, _parent, _ref )  \
  CHECK_FCT(  fd_dict_new( fd_g_config->cnf_dict, (_type), (_data), (_parent), (_ref))  );

#define CHECK_dict_search( _type, _criteria, _what, _result )  \
  CHECK_FCT(  fd_dict_search( fd_g_config->cnf_dict, (_type), (_criteria), (_what), (_result), ENOENT) );

struct local_rules_definition {
  struct dict_avp_request avp_vendor_plus_name;
  enum rule_position  position;
  int       min;
  int      max;
};

#define RULE_ORDER( _position ) ((((_position) == RULE_FIXED_HEAD) || ((_position) == RULE_FIXED_TAIL)) ? 1 : 0 )

/* Attention! This version of the macro uses AVP_BY_NAME_AND_VENDOR, in contrast to most other copies! */
#define PARSE_loc_rules( _rulearray, _parent) {                \
  int __ar;                      \
  for (__ar=0; __ar < sizeof(_rulearray) / sizeof((_rulearray)[0]); __ar++) {      \
    struct dict_rule_data __data = { NULL,               \
      (_rulearray)[__ar].position,              \
      0,                     \
      (_rulearray)[__ar].min,                \
      (_rulearray)[__ar].max};              \
    __data.rule_order = RULE_ORDER(__data.rule_position);          \
    CHECK_FCT(  fd_dict_search(                 \
      fd_g_config->cnf_dict,                \
      DICT_AVP,                   \
      AVP_BY_NAME_AND_VENDOR,               \
      &(_rulearray)[__ar].avp_vendor_plus_name,          \
      &__data.rule_avp, 0 ) );              \
    if ( !__data.rule_avp ) {                \
      TRACE_DEBUG(INFO, "AVP Not found: '%s'", (_rulearray)[__ar].avp_vendor_plus_name.avp_name);    \
      return ENOENT;                  \
    }                      \
    CHECK_FCT_DO( fd_dict_new( fd_g_config->cnf_dict, DICT_RULE, &__data, _parent, NULL),  \
      {                          \
        TRACE_DEBUG(INFO, "Error on rule with AVP '%s'",            \
              (_rulearray)[__ar].avp_vendor_plus_name.avp_name);    \
        return EINVAL;                      \
      } );                          \
  }                              \
}

#define enumval_def_u32( _val_, _str_ ) \
    { _str_,     { .u32 = _val_ }}

#define enumval_def_os( _len_, _val_, _str_ ) \
    { _str_,     { .os = { .data = (unsigned char *)_val_, .len = _len_ }}}

/*
@id	16777313
@name	SGd
*/


int ogs_dict_sgd_entry(char *conffile)
{
  /* Applications section */
  {
  {
    struct dict_object * vendor;
    CHECK_FCT(fd_dict_search(fd_g_config->cnf_dict, DICT_VENDOR, VENDOR_BY_NAME, "3GPP", &vendor, ENOENT));
    struct dict_application_data app_data = { 16777313, "SGd" };
    /* we need to modify this */
    CHECK_FCT(fd_dict_new(fd_g_config->cnf_dict, DICT_APPLICATION, &app_data, vendor, NULL));

  }}
  /*
  MO-Forward-Short-Message-Request ::= <Diameter Header: 8388645, REQ, PXY, 16777313>
      [ DRMP ]
      [ Vendor-Specific-Application-Id ]
      { Origin-Host }
      { Origin-Realm }
      [ Destination-Host ]
      { Destination-Realm }
      { SC-Address }
      [ OFR-Flags ]
  *   [ Supported-Features ]
      { User-Identifier }
      { SM-RP-UI }
      [ SMSMI-Correlation-ID ]
      [ SM-Delivery-Outcome ]
  *   [ AVP ]
  *   [ Proxy-Info ]
  *   [ Route-Record ]
  */

    /*MO-Forward-Short-Message-Request*/
  {
    struct dict_object *cmd;
    struct local_rules_definition rules[] =
    {
        { {                      .avp_name = "SC-Address"}, RULE_REQUIRED, -1, 1},
        { {                      .avp_name = "OFR-Flags" }, RULE_OPTIONAL, -1, 1 },
        { { .avp_vendor = 10415, .avp_name = "Supported-Features" }, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SM-RP-UI" }, RULE_REQUIRED, -1, 1 },
        { {                      .avp_name = "SM-Delivery-Outcome"}, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SMSMI-Correlation-ID"}, RULE_OPTIONAL, -1, 1 },

    };
    CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "MO-Forward-Short-Message-Request", &cmd);
    PARSE_loc_rules( rules, cmd );
  }
  
/*
MO-Forward-Short-Message-Answer ::= <Diameter Header: 8388645, PXY, 16777313>
      { Origin-Host }
      { Origin-Realm }
  *   [ Supported-Features ]
      [ SM-Delivery-Failure-Cause ]
      [ External-Identifier ]
  *   [ Failed-AVP ]
  *   [ Proxy-Info ]
  *   [ Route-Record ]
*/

/*MO-Forward-Short-Message-Answer*/
  {
    struct dict_object *cmd;
    struct local_rules_definition rules[] =
    {
        { { .avp_vendor = 10415, .avp_name = "Supported-Features" }, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SM-Delivery-Failure-Cause"}, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SM-RP-UI" }, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "External-Identifier"}, RULE_OPTIONAL, -1, 1 },
    };
    CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "MO-Forward-Short-Message-Answer", &cmd);
    PARSE_loc_rules( rules, cmd );
  }



/*
MT-Forward-Short-Message-Request ::= <Diameter Header: 8388646, REQ, PXY, 16777313>
      [ DRMP ]
      [ Vendor-Specific-Application-Id ]
      { Origin-Host }
      { Origin-Realm }
      { Destination-Host }
      { Destination-Realm }
      { User-Name }
  *   [ Supported-Features ]
      [ SMSMI-Correlation-ID ]
      { SC-Address }
      { SM-RP-UI }
      [ MME-Number-for-MT-SMS ]
      [ SGSN-Number ]
      [ TFR-Flags ]
      [ SM-Delivery-Timer ]
      [ SM-Delivery-Start-Time ]
      [ Maximum-Retransmission-Time ]
  *   [ AVP ]
  *   [ Proxy-Info ]
      [ DRMP ]
      [ Vendor-Specific-Application-Id ]
      [ Experimental-Result ]

*/

    /*MT-Forward-Short-Message-Request*/
    {
    struct dict_object *cmd;
    struct local_rules_definition rules[] =
    {
        { {                      .avp_name = "User-Name" }, RULE_OPTIONAL, -1, 1 },
        { { .avp_vendor = 10415, .avp_name = "Supported-Features" }, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SMSMI-Correlation-ID"}, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SC-Address"}, RULE_REQUIRED, -1, 1},
        { {                      .avp_name = "SM-RP-UI" }, RULE_REQUIRED, -1, 1 },
        { {                      .avp_name = "MME-Number-for-MT-SMS"}, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SGSN-Number"}, RULE_OPTIONAL, -1, 1 },
        { {                      .avp_name = "SM-Delivery-Timer"}, RULE_REQUIRED, -1, 1 },
        { {                      .avp_name = "SM-Delivery-Start-Time"}, RULE_REQUIRED, -1, 1 },
        { {                      .avp_name = "Maximum-Retransmission-Time"}, RULE_REQUIRED, -1, 1 }        
        
    };
    CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "MO-Forward-Short-Message-Answer", &cmd);
    PARSE_loc_rules( rules, cmd );
  }

    /*MT-Forward-Short-Message-Answer*/
    {
    struct dict_object *cmd;
    struct local_rules_definition rules[] =
    {
        { { .avp_vendor = 10415, .avp_name = "Supported-Features" }, RULE_OPTIONAL, -1, 1 },
        { { .avp_vendor = 10415, .avp_name = "SM-Delivery-Failure-Cause"}, RULE_REQUIRED, -1, 1 },
        { { .avp_vendor = 10415, .avp_name = "SM-RP-UI" }, RULE_REQUIRED, -1, 1 },
        { { .avp_vendor = 10415, .avp_name = "User-Name" }, RULE_OPTIONAL, -1, 1 },        
        { { .avp_vendor = 10415, .avp_name = "MME-Number-for-MT-SMS"}, RULE_OPTIONAL, -1, 1 },
        { { .avp_vendor = 10415, .avp_name = "SGSN-Number"}, RULE_OPTIONAL, -1, 1 },
    };
    CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "MO-Forward-Short-Message-Answer", &cmd);
    PARSE_loc_rules( rules, cmd );
  }
  return 0;
  }
