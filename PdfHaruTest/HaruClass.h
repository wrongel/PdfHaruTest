/*----- hpdf_consts.h --------------------------------------------------------*/
#ifndef _HPDF_CONSTS_H
#define _HPDF_CONSTS_H

#define MmToPx 2.834647			// ????????? ???????? ??????????? ? ???????

/*----------------------------------------------------------------------------*/

#define  HPDF_TRUE                  1
#define  HPDF_FALSE                 0

#define  HPDF_OK                    0
#define  HPDF_NOERROR               0

/*----- default values -------------------------------------------------------*/

/* buffer size which is required when we convert to character string. */
#define HPDF_TMP_BUF_SIZ            512
#define HPDF_SHORT_BUF_SIZ          32
#define HPDF_REAL_LEN               11
#define HPDF_INT_LEN                11
#define HPDF_TEXT_DEFAULT_LEN       256
#define HPDF_UNICODE_HEADER_LEN     2
#define HPDF_DATE_TIME_STR_LEN      23

/* length of each item defined in PDF */
#define HPDF_BYTE_OFFSET_LEN        10
#define HPDF_OBJ_ID_LEN             7
#define HPDF_GEN_NO_LEN             5

/* default value of Graphic State */
#define HPDF_DEF_FONT               "Helvetica"
#define HPDF_DEF_PAGE_LAYOUT        HPDF_PAGE_LAYOUT_SINGLE
#define HPDF_DEF_PAGE_MODE          HPDF_PAGE_MODE_USE_NONE
#define HPDF_DEF_WORDSPACE          0
#define HPDF_DEF_CHARSPACE          0
#define HPDF_DEF_FONTSIZE           10
#define HPDF_DEF_HSCALING           100
#define HPDF_DEF_LEADING            0
#define HPDF_DEF_RENDERING_MODE     HPDF_FILL
#define HPDF_DEF_RISE               0
#define HPDF_DEF_RAISE              HPDF_DEF_RISE
#define HPDF_DEF_LINEWIDTH          1
#define HPDF_DEF_LINECAP            HPDF_BUTT_END
#define HPDF_DEF_LINEJOIN           HPDF_MITER_JOIN
#define HPDF_DEF_MITERLIMIT         10
#define HPDF_DEF_FLATNESS           1
#define HPDF_DEF_PAGE_NUM           1

#define HPDF_BS_DEF_WIDTH           1

/* defalt page-size */
#define HPDF_DEF_PAGE_WIDTH         595.276F
#define HPDF_DEF_PAGE_HEIGHT        841.89F

/*---------------------------------------------------------------------------*/
/*----- compression mode ----------------------------------------------------*/

#define  HPDF_COMP_NONE            0x00
#define  HPDF_COMP_TEXT            0x01
#define  HPDF_COMP_IMAGE           0x02
#define  HPDF_COMP_METADATA        0x04
#define  HPDF_COMP_ALL             0x0F
/* #define  HPDF_COMP_BEST_COMPRESS   0x10
* #define  HPDF_COMP_BEST_SPEED      0x20
*/
#define  HPDF_COMP_MASK            0xFF


/*----------------------------------------------------------------------------*/
/*----- permission flags (only Revision 2 is supported)-----------------------*/

#define HPDF_ENABLE_READ         0
#define HPDF_ENABLE_PRINT        4
#define HPDF_ENABLE_EDIT_ALL     8
#define HPDF_ENABLE_COPY         16
#define HPDF_ENABLE_EDIT         32


/*----------------------------------------------------------------------------*/
/*------ viewer preferences definitions --------------------------------------*/

#define HPDF_HIDE_TOOLBAR    1
#define HPDF_HIDE_MENUBAR    2
#define HPDF_HIDE_WINDOW_UI  4
#define HPDF_FIT_WINDOW      8
#define HPDF_CENTER_WINDOW   16
#define HPDF_PRINT_SCALING_NONE   32

/*---------------------------------------------------------------------------*/
/*------ limitation of object implementation (PDF1.4) -----------------------*/

#define HPDF_LIMIT_MAX_INT             2147483647
#define HPDF_LIMIT_MIN_INT             -2147483647

#define HPDF_LIMIT_MAX_REAL             3.4E38f // per PDF 1.7 spec, Annex C, old value  32767
#define HPDF_LIMIT_MIN_REAL            -3.4E38f // per PDF 1.7 spec, Annex C, old value -32767

#define HPDF_LIMIT_MAX_STRING_LEN      2147483646 // per PDF 1.7 spec, limit 32767 is for strings in content stream and no limit in other cases => open the limit to max Integer, old value 65535
#define HPDF_LIMIT_MAX_NAME_LEN        127

#define HPDF_LIMIT_MAX_ARRAY           8388607  // per PDF 1.7 spec, "Maximum number of indirect objects in a PDF file" is 8388607, old value 8191
#define HPDF_LIMIT_MAX_DICT_ELEMENT    8388607  // per PDF 1.7 spec, "Maximum number of indirect objects in a PDF file" is 8388607, old value 4095
#define HPDF_LIMIT_MAX_XREF_ELEMENT    8388607
#define HPDF_LIMIT_MAX_GSTATE          28
#define HPDF_LIMIT_MAX_DEVICE_N        8
#define HPDF_LIMIT_MAX_DEVICE_N_V15    32
#define HPDF_LIMIT_MAX_CID             65535
#define HPDF_MAX_GENERATION_NUM        65535

#define HPDF_MIN_PAGE_HEIGHT           3
#define HPDF_MIN_PAGE_WIDTH            3
#define HPDF_MAX_PAGE_HEIGHT           14400
#define HPDF_MAX_PAGE_WIDTH            14400
#define HPDF_MIN_MAGNIFICATION_FACTOR  8
#define HPDF_MAX_MAGNIFICATION_FACTOR  3200

/*---------------------------------------------------------------------------*/
/*------ limitation of various properties -----------------------------------*/

#define HPDF_MIN_PAGE_SIZE          3
#define HPDF_MAX_PAGE_SIZE          14400
#define HPDF_MIN_HORIZONTALSCALING  10
#define HPDF_MAX_HORIZONTALSCALING  300
#define HPDF_MIN_WORDSPACE          -30
#define HPDF_MAX_WORDSPACE          300
#define HPDF_MIN_CHARSPACE          -30
#define HPDF_MAX_CHARSPACE          300
#define HPDF_MAX_FONTSIZE           600
#define HPDF_MAX_ZOOMSIZE           10
#define HPDF_MAX_LEADING            300
#define HPDF_MAX_LINEWIDTH          100
#define HPDF_MAX_DASH_PATTERN       100

#define HPDF_MAX_JWW_NUM            128

/*----------------------------------------------------------------------------*/
/*----- country code definition ----------------------------------------------*/

#define HPDF_COUNTRY_AF  "AF"    /* AFGHANISTAN */
#define HPDF_COUNTRY_AL  "AL"    /* ALBANIA */
#define HPDF_COUNTRY_DZ  "DZ"    /* ALGERIA */
#define HPDF_COUNTRY_AS  "AS"    /* AMERICAN SAMOA */
#define HPDF_COUNTRY_AD  "AD"    /* ANDORRA */
#define HPDF_COUNTRY_AO  "AO"    /* ANGOLA */
#define HPDF_COUNTRY_AI  "AI"    /* ANGUILLA */
#define HPDF_COUNTRY_AQ  "AQ"    /* ANTARCTICA */
#define HPDF_COUNTRY_AG  "AG"    /* ANTIGUA AND BARBUDA */
#define HPDF_COUNTRY_AR  "AR"    /* ARGENTINA */
#define HPDF_COUNTRY_AM  "AM"    /* ARMENIA */
#define HPDF_COUNTRY_AW  "AW"    /* ARUBA */
#define HPDF_COUNTRY_AU  "AU"    /* AUSTRALIA */
#define HPDF_COUNTRY_AT  "AT"    /* AUSTRIA */
#define HPDF_COUNTRY_AZ  "AZ"    /* AZERBAIJAN */
#define HPDF_COUNTRY_BS  "BS"    /* BAHAMAS */
#define HPDF_COUNTRY_BH  "BH"    /* BAHRAIN */
#define HPDF_COUNTRY_BD  "BD"    /* BANGLADESH */
#define HPDF_COUNTRY_BB  "BB"    /* BARBADOS */
#define HPDF_COUNTRY_BY  "BY"    /* BELARUS */
#define HPDF_COUNTRY_BE  "BE"    /* BELGIUM */
#define HPDF_COUNTRY_BZ  "BZ"    /* BELIZE */
#define HPDF_COUNTRY_BJ  "BJ"    /* BENIN */
#define HPDF_COUNTRY_BM  "BM"    /* BERMUDA */
#define HPDF_COUNTRY_BT  "BT"    /* BHUTAN */
#define HPDF_COUNTRY_BO  "BO"    /* BOLIVIA */
#define HPDF_COUNTRY_BA  "BA"    /* BOSNIA AND HERZEGOWINA */
#define HPDF_COUNTRY_BW  "BW"    /* BOTSWANA */
#define HPDF_COUNTRY_BV  "BV"    /* BOUVET ISLAND */
#define HPDF_COUNTRY_BR  "BR"    /* BRAZIL */
#define HPDF_COUNTRY_IO  "IO"    /* BRITISH INDIAN OCEAN TERRITORY */
#define HPDF_COUNTRY_BN  "BN"    /* BRUNEI DARUSSALAM */
#define HPDF_COUNTRY_BG  "BG"    /* BULGARIA */
#define HPDF_COUNTRY_BF  "BF"    /* BURKINA FASO */
#define HPDF_COUNTRY_BI  "BI"    /* BURUNDI */
#define HPDF_COUNTRY_KH  "KH"    /* CAMBODIA */
#define HPDF_COUNTRY_CM  "CM"    /* CAMEROON */
#define HPDF_COUNTRY_CA  "CA"    /* CANADA */
#define HPDF_COUNTRY_CV  "CV"    /* CAPE VERDE */
#define HPDF_COUNTRY_KY  "KY"    /* CAYMAN ISLANDS */
#define HPDF_COUNTRY_CF  "CF"    /* CENTRAL AFRICAN REPUBLIC */
#define HPDF_COUNTRY_TD  "TD"    /* CHAD */
#define HPDF_COUNTRY_CL  "CL"    /* CHILE */
#define HPDF_COUNTRY_CN  "CN"    /* CHINA */
#define HPDF_COUNTRY_CX  "CX"    /* CHRISTMAS ISLAND */
#define HPDF_COUNTRY_CC  "CC"    /* COCOS (KEELING) ISLANDS */
#define HPDF_COUNTRY_CO  "CO"    /* COLOMBIA */
#define HPDF_COUNTRY_KM  "KM"    /* COMOROS */
#define HPDF_COUNTRY_CG  "CG"    /* CONGO */
#define HPDF_COUNTRY_CK  "CK"    /* COOK ISLANDS */
#define HPDF_COUNTRY_CR  "CR"    /* COSTA RICA */
#define HPDF_COUNTRY_CI  "CI"    /* COTE D'IVOIRE */
#define HPDF_COUNTRY_HR  "HR"    /* CROATIA (local name: Hrvatska) */
#define HPDF_COUNTRY_CU  "CU"    /* CUBA */
#define HPDF_COUNTRY_CY  "CY"    /* CYPRUS */
#define HPDF_COUNTRY_CZ  "CZ"    /* CZECH REPUBLIC */
#define HPDF_COUNTRY_DK  "DK"    /* DENMARK */
#define HPDF_COUNTRY_DJ  "DJ"    /* DJIBOUTI */
#define HPDF_COUNTRY_DM  "DM"    /* DOMINICA */
#define HPDF_COUNTRY_DO  "DO"    /* DOMINICAN REPUBLIC */
#define HPDF_COUNTRY_TP  "TP"    /* EAST TIMOR */
#define HPDF_COUNTRY_EC  "EC"    /* ECUADOR */
#define HPDF_COUNTRY_EG  "EG"    /* EGYPT */
#define HPDF_COUNTRY_SV  "SV"    /* EL SALVADOR */
#define HPDF_COUNTRY_GQ  "GQ"    /* EQUATORIAL GUINEA */
#define HPDF_COUNTRY_ER  "ER"    /* ERITREA */
#define HPDF_COUNTRY_EE  "EE"    /* ESTONIA */
#define HPDF_COUNTRY_ET  "ET"    /* ETHIOPIA */
#define HPDF_COUNTRY_FK  "FK"   /* FALKLAND ISLANDS (MALVINAS) */
#define HPDF_COUNTRY_FO  "FO"    /* FAROE ISLANDS */
#define HPDF_COUNTRY_FJ  "FJ"    /* FIJI */
#define HPDF_COUNTRY_FI  "FI"    /* FINLAND */
#define HPDF_COUNTRY_FR  "FR"    /* FRANCE */
#define HPDF_COUNTRY_FX  "FX"    /* FRANCE, METROPOLITAN */
#define HPDF_COUNTRY_GF  "GF"    /* FRENCH GUIANA */
#define HPDF_COUNTRY_PF  "PF"    /* FRENCH POLYNESIA */
#define HPDF_COUNTRY_TF  "TF"    /* FRENCH SOUTHERN TERRITORIES */
#define HPDF_COUNTRY_GA  "GA"    /* GABON */
#define HPDF_COUNTRY_GM  "GM"    /* GAMBIA */
#define HPDF_COUNTRY_GE  "GE"    /* GEORGIA */
#define HPDF_COUNTRY_DE  "DE"    /* GERMANY */
#define HPDF_COUNTRY_GH  "GH"    /* GHANA */
#define HPDF_COUNTRY_GI  "GI"    /* GIBRALTAR */
#define HPDF_COUNTRY_GR  "GR"    /* GREECE */
#define HPDF_COUNTRY_GL  "GL"    /* GREENLAND */
#define HPDF_COUNTRY_GD  "GD"    /* GRENADA */
#define HPDF_COUNTRY_GP  "GP"    /* GUADELOUPE */
#define HPDF_COUNTRY_GU  "GU"    /* GUAM */
#define HPDF_COUNTRY_GT  "GT"    /* GUATEMALA */
#define HPDF_COUNTRY_GN  "GN"    /* GUINEA */
#define HPDF_COUNTRY_GW  "GW"    /* GUINEA-BISSAU */
#define HPDF_COUNTRY_GY  "GY"    /* GUYANA */
#define HPDF_COUNTRY_HT  "HT"    /* HAITI */
#define HPDF_COUNTRY_HM  "HM"    /* HEARD AND MC DONALD ISLANDS */
#define HPDF_COUNTRY_HN  "HN"    /* HONDURAS */
#define HPDF_COUNTRY_HK  "HK"    /* HONG KONG */
#define HPDF_COUNTRY_HU  "HU"    /* HUNGARY */
#define HPDF_COUNTRY_IS  "IS"    /* ICELAND */
#define HPDF_COUNTRY_IN  "IN"    /* INDIA */
#define HPDF_COUNTRY_ID  "ID"    /* INDONESIA */
#define HPDF_COUNTRY_IR  "IR"    /* IRAN (ISLAMIC REPUBLIC OF) */
#define HPDF_COUNTRY_IQ  "IQ"    /* IRAQ */
#define HPDF_COUNTRY_IE  "IE"    /* IRELAND */
#define HPDF_COUNTRY_IL  "IL"    /* ISRAEL */
#define HPDF_COUNTRY_IT  "IT"    /* ITALY */
#define HPDF_COUNTRY_JM  "JM"    /* JAMAICA */
#define HPDF_COUNTRY_JP  "JP"    /* JAPAN */
#define HPDF_COUNTRY_JO  "JO"    /* JORDAN */
#define HPDF_COUNTRY_KZ  "KZ"    /* KAZAKHSTAN */
#define HPDF_COUNTRY_KE  "KE"    /* KENYA */
#define HPDF_COUNTRY_KI  "KI"    /* KIRIBATI */
#define HPDF_COUNTRY_KP  "KP"    /* KOREA, DEMOCRATIC PEOPLE'S REPUBLIC OF */
#define HPDF_COUNTRY_KR  "KR"    /* KOREA, REPUBLIC OF */
#define HPDF_COUNTRY_KW  "KW"    /* KUWAIT */
#define HPDF_COUNTRY_KG  "KG"    /* KYRGYZSTAN */
#define HPDF_COUNTRY_LA  "LA"    /* LAO PEOPLE'S DEMOCRATIC REPUBLIC */
#define HPDF_COUNTRY_LV  "LV"    /* LATVIA */
#define HPDF_COUNTRY_LB  "LB"    /* LEBANON */
#define HPDF_COUNTRY_LS  "LS"    /* LESOTHO */
#define HPDF_COUNTRY_LR  "LR"    /* LIBERIA */
#define HPDF_COUNTRY_LY  "LY"    /* LIBYAN ARAB JAMAHIRIYA */
#define HPDF_COUNTRY_LI  "LI"    /* LIECHTENSTEIN */
#define HPDF_COUNTRY_LT  "LT"    /* LITHUANIA */
#define HPDF_COUNTRY_LU  "LU"    /* LUXEMBOURG */
#define HPDF_COUNTRY_MO  "MO"    /* MACAU */
#define HPDF_COUNTRY_MK  "MK"   /* MACEDONIA, THE FORMER YUGOSLAV REPUBLIC OF */
#define HPDF_COUNTRY_MG  "MG"    /* MADAGASCAR */
#define HPDF_COUNTRY_MW  "MW"    /* MALAWI */
#define HPDF_COUNTRY_MY  "MY"    /* MALAYSIA */
#define HPDF_COUNTRY_MV  "MV"    /* MALDIVES */
#define HPDF_COUNTRY_ML  "ML"    /* MALI */
#define HPDF_COUNTRY_MT  "MT"    /* MALTA */
#define HPDF_COUNTRY_MH  "MH"    /* MARSHALL ISLANDS */
#define HPDF_COUNTRY_MQ  "MQ"    /* MARTINIQUE */
#define HPDF_COUNTRY_MR  "MR"    /* MAURITANIA */
#define HPDF_COUNTRY_MU  "MU"    /* MAURITIUS */
#define HPDF_COUNTRY_YT  "YT"    /* MAYOTTE */
#define HPDF_COUNTRY_MX  "MX"    /* MEXICO */
#define HPDF_COUNTRY_FM  "FM"    /* MICRONESIA, FEDERATED STATES OF */
#define HPDF_COUNTRY_MD  "MD"    /* MOLDOVA, REPUBLIC OF */
#define HPDF_COUNTRY_MC  "MC"    /* MONACO */
#define HPDF_COUNTRY_MN  "MN"    /* MONGOLIA */
#define HPDF_COUNTRY_MS  "MS"    /* MONTSERRAT */
#define HPDF_COUNTRY_MA  "MA"    /* MOROCCO */
#define HPDF_COUNTRY_MZ  "MZ"    /* MOZAMBIQUE */
#define HPDF_COUNTRY_MM  "MM"    /* MYANMAR */
#define HPDF_COUNTRY_NA  "NA"    /* NAMIBIA */
#define HPDF_COUNTRY_NR  "NR"    /* NAURU */
#define HPDF_COUNTRY_NP  "NP"    /* NEPAL */
#define HPDF_COUNTRY_NL  "NL"    /* NETHERLANDS */
#define HPDF_COUNTRY_AN  "AN"    /* NETHERLANDS ANTILLES */
#define HPDF_COUNTRY_NC  "NC"    /* NEW CALEDONIA */
#define HPDF_COUNTRY_NZ  "NZ"    /* NEW ZEALAND */
#define HPDF_COUNTRY_NI  "NI"    /* NICARAGUA */
#define HPDF_COUNTRY_NE  "NE"    /* NIGER */
#define HPDF_COUNTRY_NG  "NG"    /* NIGERIA */
#define HPDF_COUNTRY_NU  "NU"    /* NIUE */
#define HPDF_COUNTRY_NF  "NF"    /* NORFOLK ISLAND */
#define HPDF_COUNTRY_MP  "MP"    /* NORTHERN MARIANA ISLANDS */
#define HPDF_COUNTRY_NO  "NO"    /* NORWAY */
#define HPDF_COUNTRY_OM  "OM"    /* OMAN */
#define HPDF_COUNTRY_PK  "PK"    /* PAKISTAN */
#define HPDF_COUNTRY_PW  "PW"    /* PALAU */
#define HPDF_COUNTRY_PA  "PA"    /* PANAMA */
#define HPDF_COUNTRY_PG  "PG"    /* PAPUA NEW GUINEA */
#define HPDF_COUNTRY_PY  "PY"    /* PARAGUAY */
#define HPDF_COUNTRY_PE  "PE"    /* PERU */
#define HPDF_COUNTRY_PH  "PH"    /* PHILIPPINES */
#define HPDF_COUNTRY_PN  "PN"    /* PITCAIRN */
#define HPDF_COUNTRY_PL  "PL"    /* POLAND */
#define HPDF_COUNTRY_PT  "PT"    /* PORTUGAL */
#define HPDF_COUNTRY_PR  "PR"    /* PUERTO RICO */
#define HPDF_COUNTRY_QA  "QA"    /* QATAR */
#define HPDF_COUNTRY_RE  "RE"    /* REUNION */
#define HPDF_COUNTRY_RO  "RO"    /* ROMANIA */
#define HPDF_COUNTRY_RU  "RU"    /* RUSSIAN FEDERATION */
#define HPDF_COUNTRY_RW  "RW"    /* RWANDA */
#define HPDF_COUNTRY_KN  "KN"    /* SAINT KITTS AND NEVIS */
#define HPDF_COUNTRY_LC  "LC"    /* SAINT LUCIA */
#define HPDF_COUNTRY_VC  "VC"    /* SAINT VINCENT AND THE GRENADINES */
#define HPDF_COUNTRY_WS  "WS"    /* SAMOA */
#define HPDF_COUNTRY_SM  "SM"    /* SAN MARINO */
#define HPDF_COUNTRY_ST  "ST"    /* SAO TOME AND PRINCIPE */
#define HPDF_COUNTRY_SA  "SA"    /* SAUDI ARABIA */
#define HPDF_COUNTRY_SN  "SN"    /* SENEGAL */
#define HPDF_COUNTRY_SC  "SC"    /* SEYCHELLES */
#define HPDF_COUNTRY_SL  "SL"    /* SIERRA LEONE */
#define HPDF_COUNTRY_SG  "SG"    /* SINGAPORE */
#define HPDF_COUNTRY_SK  "SK"    /* SLOVAKIA (Slovak Republic) */
#define HPDF_COUNTRY_SI  "SI"    /* SLOVENIA */
#define HPDF_COUNTRY_SB  "SB"    /* SOLOMON ISLANDS */
#define HPDF_COUNTRY_SO  "SO"    /* SOMALIA */
#define HPDF_COUNTRY_ZA  "ZA"    /* SOUTH AFRICA */
#define HPDF_COUNTRY_ES  "ES"    /* SPAIN */
#define HPDF_COUNTRY_LK  "LK"    /* SRI LANKA */
#define HPDF_COUNTRY_SH  "SH"    /* ST. HELENA */
#define HPDF_COUNTRY_PM  "PM"    /* ST. PIERRE AND MIQUELON */
#define HPDF_COUNTRY_SD  "SD"    /* SUDAN */
#define HPDF_COUNTRY_SR  "SR"    /* SURINAME */
#define HPDF_COUNTRY_SJ  "SJ"    /* SVALBARD AND JAN MAYEN ISLANDS */
#define HPDF_COUNTRY_SZ  "SZ"    /* SWAZILAND */
#define HPDF_COUNTRY_SE  "SE"    /* SWEDEN */
#define HPDF_COUNTRY_CH  "CH"    /* SWITZERLAND */
#define HPDF_COUNTRY_SY  "SY"    /* SYRIAN ARAB REPUBLIC */
#define HPDF_COUNTRY_TW  "TW"    /* TAIWAN, PROVINCE OF CHINA */
#define HPDF_COUNTRY_TJ  "TJ"    /* TAJIKISTAN */
#define HPDF_COUNTRY_TZ  "TZ"    /* TANZANIA, UNITED REPUBLIC OF */
#define HPDF_COUNTRY_TH  "TH"    /* THAILAND */
#define HPDF_COUNTRY_TG  "TG"    /* TOGO */
#define HPDF_COUNTRY_TK  "TK"    /* TOKELAU */
#define HPDF_COUNTRY_TO  "TO"    /* TONGA */
#define HPDF_COUNTRY_TT  "TT"    /* TRINIDAD AND TOBAGO */
#define HPDF_COUNTRY_TN  "TN"    /* TUNISIA */
#define HPDF_COUNTRY_TR  "TR"    /* TURKEY */
#define HPDF_COUNTRY_TM  "TM"    /* TURKMENISTAN */
#define HPDF_COUNTRY_TC  "TC"    /* TURKS AND CAICOS ISLANDS */
#define HPDF_COUNTRY_TV  "TV"    /* TUVALU */
#define HPDF_COUNTRY_UG  "UG"    /* UGANDA */
#define HPDF_COUNTRY_UA  "UA"    /* UKRAINE */
#define HPDF_COUNTRY_AE  "AE"    /* UNITED ARAB EMIRATES */
#define HPDF_COUNTRY_GB  "GB"    /* UNITED KINGDOM */
#define HPDF_COUNTRY_US  "US"    /* UNITED STATES */
#define HPDF_COUNTRY_UM  "UM"    /* UNITED STATES MINOR OUTLYING ISLANDS */
#define HPDF_COUNTRY_UY  "UY"    /* URUGUAY */
#define HPDF_COUNTRY_UZ  "UZ"    /* UZBEKISTAN */
#define HPDF_COUNTRY_VU  "VU"    /* VANUATU */
#define HPDF_COUNTRY_VA  "VA"    /* VATICAN CITY STATE (HOLY SEE) */
#define HPDF_COUNTRY_VE  "VE"    /* VENEZUELA */
#define HPDF_COUNTRY_VN  "VN"    /* VIET NAM */
#define HPDF_COUNTRY_VG  "VG"    /* VIRGIN ISLANDS (BRITISH) */
#define HPDF_COUNTRY_VI  "VI"    /* VIRGIN ISLANDS (U.S.) */
#define HPDF_COUNTRY_WF  "WF"    /* WALLIS AND FUTUNA ISLANDS */
#define HPDF_COUNTRY_EH  "EH"    /* WESTERN SAHARA */
#define HPDF_COUNTRY_YE  "YE"    /* YEMEN */
#define HPDF_COUNTRY_YU  "YU"    /* YUGOSLAVIA */
#define HPDF_COUNTRY_ZR  "ZR"    /* ZAIRE */
#define HPDF_COUNTRY_ZM  "ZM"    /* ZAMBIA */
#define HPDF_COUNTRY_ZW  "ZW"    /* ZIMBABWE */

/*----------------------------------------------------------------------------*/
/*----- lang code definition -------------------------------------------------*/

#define HPDF_LANG_AA    "aa"     /* Afar */
#define HPDF_LANG_AB    "ab"     /* Abkhazian */
#define HPDF_LANG_AF    "af"     /* Afrikaans */
#define HPDF_LANG_AM    "am"     /* Amharic */
#define HPDF_LANG_AR    "ar"     /* Arabic */
#define HPDF_LANG_AS    "as"     /* Assamese */
#define HPDF_LANG_AY    "ay"     /* Aymara */
#define HPDF_LANG_AZ    "az"     /* Azerbaijani */
#define HPDF_LANG_BA    "ba"     /* Bashkir */
#define HPDF_LANG_BE    "be"     /* Byelorussian */
#define HPDF_LANG_BG    "bg"     /* Bulgarian */
#define HPDF_LANG_BH    "bh"     /* Bihari */
#define HPDF_LANG_BI    "bi"     /* Bislama */
#define HPDF_LANG_BN    "bn"     /* Bengali Bangla */
#define HPDF_LANG_BO    "bo"     /* Tibetan */
#define HPDF_LANG_BR    "br"     /* Breton */
#define HPDF_LANG_CA    "ca"     /* Catalan */
#define HPDF_LANG_CO    "co"     /* Corsican */
#define HPDF_LANG_CS    "cs"     /* Czech */
#define HPDF_LANG_CY    "cy"     /* Welsh */
#define HPDF_LANG_DA    "da"     /* Danish */
#define HPDF_LANG_DE    "de"     /* German */
#define HPDF_LANG_DZ    "dz"     /* Bhutani */
#define HPDF_LANG_EL    "el"     /* Greek */
#define HPDF_LANG_EN    "en"     /* English */
#define HPDF_LANG_EO    "eo"     /* Esperanto */
#define HPDF_LANG_ES    "es"     /* Spanish */
#define HPDF_LANG_ET    "et"     /* Estonian */
#define HPDF_LANG_EU    "eu"     /* Basque */
#define HPDF_LANG_FA    "fa"     /* Persian */
#define HPDF_LANG_FI    "fi"     /* Finnish */
#define HPDF_LANG_FJ    "fj"     /* Fiji */
#define HPDF_LANG_FO    "fo"     /* Faeroese */
#define HPDF_LANG_FR    "fr"     /* French */
#define HPDF_LANG_FY    "fy"     /* Frisian */
#define HPDF_LANG_GA    "ga"     /* Irish */
#define HPDF_LANG_GD    "gd"     /* Scots Gaelic */
#define HPDF_LANG_GL    "gl"     /* Galician */
#define HPDF_LANG_GN    "gn"     /* Guarani */
#define HPDF_LANG_GU    "gu"     /* Gujarati */
#define HPDF_LANG_HA    "ha"     /* Hausa */
#define HPDF_LANG_HI    "hi"     /* Hindi */
#define HPDF_LANG_HR    "hr"     /* Croatian */
#define HPDF_LANG_HU    "hu"     /* Hungarian */
#define HPDF_LANG_HY    "hy"     /* Armenian */
#define HPDF_LANG_IA    "ia"     /* Interlingua */
#define HPDF_LANG_IE    "ie"     /* Interlingue */
#define HPDF_LANG_IK    "ik"     /* Inupiak */
#define HPDF_LANG_IN    "in"     /* Indonesian */
#define HPDF_LANG_IS    "is"     /* Icelandic */
#define HPDF_LANG_IT    "it"     /* Italian */
#define HPDF_LANG_IW    "iw"     /* Hebrew */
#define HPDF_LANG_JA    "ja"     /* Japanese */
#define HPDF_LANG_JI    "ji"     /* Yiddish */
#define HPDF_LANG_JW    "jw"     /* Javanese */
#define HPDF_LANG_KA    "ka"     /* Georgian */
#define HPDF_LANG_KK    "kk"     /* Kazakh */
#define HPDF_LANG_KL    "kl"     /* Greenlandic */
#define HPDF_LANG_KM    "km"     /* Cambodian */
#define HPDF_LANG_KN    "kn"     /* Kannada */
#define HPDF_LANG_KO    "ko"     /* Korean */
#define HPDF_LANG_KS    "ks"     /* Kashmiri */
#define HPDF_LANG_KU    "ku"     /* Kurdish */
#define HPDF_LANG_KY    "ky"     /* Kirghiz */
#define HPDF_LANG_LA    "la"     /* Latin */
#define HPDF_LANG_LN    "ln"     /* Lingala */
#define HPDF_LANG_LO    "lo"     /* Laothian */
#define HPDF_LANG_LT    "lt"     /* Lithuanian */
#define HPDF_LANG_LV    "lv"     /* Latvian,Lettish */
#define HPDF_LANG_MG    "mg"     /* Malagasy */
#define HPDF_LANG_MI    "mi"     /* Maori */
#define HPDF_LANG_MK    "mk"     /* Macedonian */
#define HPDF_LANG_ML    "ml"     /* Malayalam */
#define HPDF_LANG_MN    "mn"     /* Mongolian */
#define HPDF_LANG_MO    "mo"     /* Moldavian */
#define HPDF_LANG_MR    "mr"     /* Marathi */
#define HPDF_LANG_MS    "ms"     /* Malay */
#define HPDF_LANG_MT    "mt"     /* Maltese */
#define HPDF_LANG_MY    "my"     /* Burmese */
#define HPDF_LANG_NA    "na"     /* Nauru */
#define HPDF_LANG_NE    "ne"     /* Nepali */
#define HPDF_LANG_NL    "nl"     /* Dutch */
#define HPDF_LANG_NO    "no"     /* Norwegian */
#define HPDF_LANG_OC    "oc"     /* Occitan */
#define HPDF_LANG_OM    "om"     /* (Afan)Oromo */
#define HPDF_LANG_OR    "or"     /* Oriya */
#define HPDF_LANG_PA    "pa"     /* Punjabi */
#define HPDF_LANG_PL    "pl"     /* Polish */
#define HPDF_LANG_PS    "ps"     /* Pashto,Pushto */
#define HPDF_LANG_PT    "pt"     /* Portuguese  */
#define HPDF_LANG_QU    "qu"     /* Quechua */
#define HPDF_LANG_RM    "rm"     /* Rhaeto-Romance */
#define HPDF_LANG_RN    "rn"     /* Kirundi */
#define HPDF_LANG_RO    "ro"     /* Romanian */
#define HPDF_LANG_RU    "ru"     /* Russian */
#define HPDF_LANG_RW    "rw"     /* Kinyarwanda */
#define HPDF_LANG_SA    "sa"     /* Sanskrit */
#define HPDF_LANG_SD    "sd"     /* Sindhi */
#define HPDF_LANG_SG    "sg"     /* Sangro */
#define HPDF_LANG_SH    "sh"     /* Serbo-Croatian */
#define HPDF_LANG_SI    "si"     /* Singhalese */
#define HPDF_LANG_SK    "sk"     /* Slovak */
#define HPDF_LANG_SL    "sl"     /* Slovenian */
#define HPDF_LANG_SM    "sm"     /* Samoan */
#define HPDF_LANG_SN    "sn"     /* Shona */
#define HPDF_LANG_SO    "so"     /* Somali */
#define HPDF_LANG_SQ    "sq"     /* Albanian */
#define HPDF_LANG_SR    "sr"     /* Serbian */
#define HPDF_LANG_SS    "ss"     /* Siswati */
#define HPDF_LANG_ST    "st"     /* Sesotho */
#define HPDF_LANG_SU    "su"     /* Sundanese */
#define HPDF_LANG_SV    "sv"     /* Swedish */
#define HPDF_LANG_SW    "sw"     /* Swahili */
#define HPDF_LANG_TA    "ta"     /* Tamil */
#define HPDF_LANG_TE    "te"     /* Tegulu */
#define HPDF_LANG_TG    "tg"     /* Tajik */
#define HPDF_LANG_TH    "th"     /* Thai */
#define HPDF_LANG_TI    "ti"     /* Tigrinya */
#define HPDF_LANG_TK    "tk"     /* Turkmen */
#define HPDF_LANG_TL    "tl"     /* Tagalog */
#define HPDF_LANG_TN    "tn"     /* Setswanato Tonga */
#define HPDF_LANG_TR    "tr"     /* Turkish */
#define HPDF_LANG_TS    "ts"     /* Tsonga */
#define HPDF_LANG_TT    "tt"     /* Tatar */
#define HPDF_LANG_TW    "tw"     /* Twi */
#define HPDF_LANG_UK    "uk"     /* Ukrainian */
#define HPDF_LANG_UR    "ur"     /* Urdu */
#define HPDF_LANG_UZ    "uz"     /* Uzbek */
#define HPDF_LANG_VI    "vi"     /* Vietnamese */
#define HPDF_LANG_VO    "vo"     /* Volapuk */
#define HPDF_LANG_WO    "wo"     /* Wolof */
#define HPDF_LANG_XH    "xh"     /* Xhosa */
#define HPDF_LANG_YO    "yo"     /* Yoruba */
#define HPDF_LANG_ZH    "zh"     /* Chinese */
#define HPDF_LANG_ZU    "zu"     /* Zulu */


/*----------------------------------------------------------------------------*/
/*----- Graphis mode ---------------------------------------------------------*/

#define   HPDF_GMODE_PAGE_DESCRIPTION       0x0001
#define   HPDF_GMODE_PATH_OBJECT            0x0002
#define   HPDF_GMODE_TEXT_OBJECT            0x0004
#define   HPDF_GMODE_CLIPPING_PATH          0x0008
#define   HPDF_GMODE_SHADING                0x0010
#define   HPDF_GMODE_INLINE_IMAGE           0x0020
#define   HPDF_GMODE_EXTERNAL_OBJECT        0x0040

/*----------------------------------------------------------------------------*/

#endif /* _HPDF_CONSTS_H */

/*----- hpdf_types.h ---------------------------------------------------------*/
#ifndef _HPDF_TYPES_H
#define _HPDF_TYPES_H

//#include <stdlib.h>

	/*----------------------------------------------------------------------------*/
	/*----- type definition ------------------------------------------------------*/


	/*  native OS integer types */
	typedef  signed int          HPDF_INT;
	typedef  unsigned int        HPDF_UINT;


	/*  32bit integer types
	*/
	typedef  signed int          HPDF_INT32;
	typedef  unsigned int        HPDF_UINT32;


	/*  16bit integer types
	*/
	typedef  signed short        HPDF_INT16;
	typedef  unsigned short      HPDF_UINT16;


	/*  8bit integer types
	*/
	typedef  signed char         HPDF_INT8;
	typedef  unsigned char       HPDF_UINT8;


	/*  8bit binary types
	*/
	typedef  unsigned char       HPDF_BYTE;


	/*  float type (32bit IEEE754)
	*/
	typedef  float               HPDF_REAL;


	/*  double type (64bit IEEE754)
	*/
	typedef  double              HPDF_DOUBLE;


	/*  boolean type (0: False, !0: True)
	*/
	typedef  signed int          HPDF_BOOL;


	/*  error-no type (32bit unsigned integer)
	*/
	typedef  unsigned long       HPDF_STATUS;


	/*  charactor-code type (16bit)
	*/
	typedef  HPDF_UINT16         HPDF_CID;
	typedef  HPDF_UINT16         HPDF_UNICODE;


	/*  HPDF_Point struct
	*/
	typedef  struct  _HPDF_Point {
		HPDF_REAL  x;
		HPDF_REAL  y;
	} HPDF_Point;

	typedef  struct _HPDF_Rect {
		HPDF_REAL  left;
		HPDF_REAL  bottom;
		HPDF_REAL  right;
		HPDF_REAL  top;
	} HPDF_Rect;

	/*  HPDF_Point3D struct
	*/
	typedef  struct  _HPDF_Point3D {
		HPDF_REAL  x;
		HPDF_REAL  y;
		HPDF_REAL  z;
	} HPDF_Point3D;

	typedef struct _HPDF_Rect HPDF_Box;

	/* HPDF_Date struct
	*/
	typedef  struct  _HPDF_Date {
		HPDF_INT    year;
		HPDF_INT    month;
		HPDF_INT    day;
		HPDF_INT    hour;
		HPDF_INT    minutes;
		HPDF_INT    seconds;
		char        ind;
		HPDF_INT    off_hour;
		HPDF_INT    off_minutes;
	} HPDF_Date;


	typedef enum _HPDF_InfoType {
		/* date-time type parameters */
		HPDF_INFO_CREATION_DATE = 0,
		HPDF_INFO_MOD_DATE,

		/* string type parameters */
		HPDF_INFO_AUTHOR,
		HPDF_INFO_CREATOR,
		HPDF_INFO_PRODUCER,
		HPDF_INFO_TITLE,
		HPDF_INFO_SUBJECT,
		HPDF_INFO_KEYWORDS,
		HPDF_INFO_TRAPPED,
		HPDF_INFO_GTS_PDFX,
		HPDF_INFO_EOF
	} HPDF_InfoType;

	/* PDF-A Types */

	typedef enum _HPDF_PDFA_TYPE
	{
		HPDF_PDFA_1A = 0,
		HPDF_PDFA_1B = 1
	} HPDF_PDFAType;


	typedef enum _HPDF_PdfVer {
		HPDF_VER_12 = 0,
		HPDF_VER_13,
		HPDF_VER_14,
		HPDF_VER_15,
		HPDF_VER_16,
		HPDF_VER_17,
		HPDF_VER_EOF
	} HPDF_PDFVer;

	typedef enum  _HPDF_EncryptMode {
		HPDF_ENCRYPT_R2 = 2,
		HPDF_ENCRYPT_R3 = 3
	} HPDF_EncryptMode;


	typedef void
	(__stdcall* HPDF_Error_Handler)  (HPDF_STATUS   error_no,
		HPDF_STATUS   detail_no,
		void         *user_data);

	typedef void*
		(__stdcall* HPDF_Alloc_Func)  (HPDF_UINT  size);


	typedef void
	(__stdcall* HPDF_Free_Func)  (void  *aptr);


	/*---------------------------------------------------------------------------*/
	/*------ text width struct --------------------------------------------------*/

	typedef struct _HPDF_TextWidth {
		HPDF_UINT numchars;

		/* don't use this value (it may be change in the feature).
		use numspace as alternated. */
		HPDF_UINT numwords;

		HPDF_UINT width;
		HPDF_UINT numspace;
	} HPDF_TextWidth;


	/*---------------------------------------------------------------------------*/
	/*------ dash mode ----------------------------------------------------------*/

	typedef struct _HPDF_DashMode {
		HPDF_UINT16  ptn[8];
		HPDF_UINT    num_ptn;
		HPDF_UINT    phase;
	} HPDF_DashMode;


	/*---------------------------------------------------------------------------*/
	/*----- HPDF_TransMatrix struct ---------------------------------------------*/

	typedef struct _HPDF_TransMatrix {
		HPDF_REAL   a;
		HPDF_REAL   b;
		HPDF_REAL   c;
		HPDF_REAL   d;
		HPDF_REAL   x;
		HPDF_REAL   y;
	} HPDF_TransMatrix;

	/*---------------------------------------------------------------------------*/
	/*----- HPDF_3DMatrix struct ------------------------------------------------*/

	typedef struct _HPDF_3DMatrix {
		HPDF_REAL   a;
		HPDF_REAL   b;
		HPDF_REAL   c;
		HPDF_REAL   d;
		HPDF_REAL   e;
		HPDF_REAL   f;
		HPDF_REAL   g;
		HPDF_REAL   h;
		HPDF_REAL   i;
		HPDF_REAL   tx;
		HPDF_REAL   ty;
		HPDF_REAL   tz;
	} HPDF_3DMatrix;

	/*---------------------------------------------------------------------------*/

	typedef enum _HPDF_ColorSpace {
		HPDF_CS_DEVICE_GRAY = 0,
		HPDF_CS_DEVICE_RGB,
		HPDF_CS_DEVICE_CMYK,
		HPDF_CS_CAL_GRAY,
		HPDF_CS_CAL_RGB,
		HPDF_CS_LAB,
		HPDF_CS_ICC_BASED,
		HPDF_CS_SEPARATION,
		HPDF_CS_DEVICE_N,
		HPDF_CS_INDEXED,
		HPDF_CS_PATTERN,
		HPDF_CS_EOF
	} HPDF_ColorSpace;

	/*---------------------------------------------------------------------------*/
	/*----- HPDF_RGBColor struct ------------------------------------------------*/

	typedef struct _HPDF_RGBColor {
		HPDF_REAL   r;
		HPDF_REAL   g;
		HPDF_REAL   b;
	} HPDF_RGBColor;

	/*---------------------------------------------------------------------------*/
	/*----- HPDF_CMYKColor struct -----------------------------------------------*/

	typedef struct _HPDF_CMYKColor {
		HPDF_REAL   c;
		HPDF_REAL   m;
		HPDF_REAL   y;
		HPDF_REAL   k;
	} HPDF_CMYKColor;

	/*---------------------------------------------------------------------------*/
	/*------ The line cap style -------------------------------------------------*/

	typedef enum _HPDF_LineCap {
		HPDF_BUTT_END = 0,
		HPDF_ROUND_END,
		HPDF_PROJECTING_SCUARE_END,
		HPDF_LINECAP_EOF
	} HPDF_LineCap;

	/*----------------------------------------------------------------------------*/
	/*------ The line join style -------------------------------------------------*/

	typedef enum _HPDF_LineJoin {
		HPDF_MITER_JOIN = 0,
		HPDF_ROUND_JOIN,
		HPDF_BEVEL_JOIN,
		HPDF_LINEJOIN_EOF
	} HPDF_LineJoin;

	/*----------------------------------------------------------------------------*/
	/*------ The text rendering mode ---------------------------------------------*/

	typedef enum _HPDF_TextRenderingMode {
		HPDF_FILL = 0,
		HPDF_STROKE,
		HPDF_FILL_THEN_STROKE,
		HPDF_INVISIBLE,
		HPDF_FILL_CLIPPING,
		HPDF_STROKE_CLIPPING,
		HPDF_FILL_STROKE_CLIPPING,
		HPDF_CLIPPING,
		HPDF_RENDERING_MODE_EOF
	} HPDF_TextRenderingMode;


	typedef enum _HPDF_WritingMode {
		HPDF_WMODE_HORIZONTAL = 0,
		HPDF_WMODE_VERTICAL,
		HPDF_WMODE_EOF
	} HPDF_WritingMode;


	typedef enum _HPDF_PageLayout {
		HPDF_PAGE_LAYOUT_SINGLE = 0,
		HPDF_PAGE_LAYOUT_ONE_COLUMN,
		HPDF_PAGE_LAYOUT_TWO_COLUMN_LEFT,
		HPDF_PAGE_LAYOUT_TWO_COLUMN_RIGHT,
		HPDF_PAGE_LAYOUT_TWO_PAGE_LEFT,
		HPDF_PAGE_LAYOUT_TWO_PAGE_RIGHT,
		HPDF_PAGE_LAYOUT_EOF
	} HPDF_PageLayout;


	typedef enum _HPDF_PageMode {
		HPDF_PAGE_MODE_USE_NONE = 0,
		HPDF_PAGE_MODE_USE_OUTLINE,
		HPDF_PAGE_MODE_USE_THUMBS,
		HPDF_PAGE_MODE_FULL_SCREEN,
		/*  HPDF_PAGE_MODE_USE_OC,
		HPDF_PAGE_MODE_USE_ATTACHMENTS,
		*/
		HPDF_PAGE_MODE_EOF
	} HPDF_PageMode;


	typedef enum _HPDF_PageNumStyle {
		HPDF_PAGE_NUM_STYLE_DECIMAL = 0,
		HPDF_PAGE_NUM_STYLE_UPPER_ROMAN,
		HPDF_PAGE_NUM_STYLE_LOWER_ROMAN,
		HPDF_PAGE_NUM_STYLE_UPPER_LETTERS,
		HPDF_PAGE_NUM_STYLE_LOWER_LETTERS,
		HPDF_PAGE_NUM_STYLE_EOF
	} HPDF_PageNumStyle;


	typedef enum _HPDF_DestinationType {
		HPDF_XYZ = 0,
		HPDF_FIT,
		HPDF_FIT_H,
		HPDF_FIT_V,
		HPDF_FIT_R,
		HPDF_FIT_B,
		HPDF_FIT_BH,
		HPDF_FIT_BV,
		HPDF_DST_EOF
	} HPDF_DestinationType;


	typedef enum _HPDF_AnnotType {
		HPDF_ANNOT_TEXT_NOTES,
		HPDF_ANNOT_LINK,
		HPDF_ANNOT_SOUND,
		HPDF_ANNOT_FREE_TEXT,
		HPDF_ANNOT_STAMP,
		HPDF_ANNOT_SQUARE,
		HPDF_ANNOT_CIRCLE,
		HPDF_ANNOT_STRIKE_OUT,
		HPDF_ANNOT_HIGHTLIGHT,
		HPDF_ANNOT_UNDERLINE,
		HPDF_ANNOT_INK,
		HPDF_ANNOT_FILE_ATTACHMENT,
		HPDF_ANNOT_POPUP,
		HPDF_ANNOT_3D,
		HPDF_ANNOT_SQUIGGLY,
		HPDF_ANNOT_LINE,
		HPDF_ANNOT_PROJECTION,
		HPDF_ANNOT_WIDGET
	} HPDF_AnnotType;


	typedef enum _HPDF_AnnotFlgs {
		HPDF_ANNOT_INVISIBLE,
		HPDF_ANNOT_HIDDEN,
		HPDF_ANNOT_PRINT,
		HPDF_ANNOT_NOZOOM,
		HPDF_ANNOT_NOROTATE,
		HPDF_ANNOT_NOVIEW,
		HPDF_ANNOT_READONLY
	} HPDF_AnnotFlgs;


	typedef enum _HPDF_AnnotHighlightMode {
		HPDF_ANNOT_NO_HIGHTLIGHT = 0,
		HPDF_ANNOT_INVERT_BOX,
		HPDF_ANNOT_INVERT_BORDER,
		HPDF_ANNOT_DOWN_APPEARANCE,
		HPDF_ANNOT_HIGHTLIGHT_MODE_EOF
	} HPDF_AnnotHighlightMode;


	typedef enum _HPDF_AnnotIcon {
		HPDF_ANNOT_ICON_COMMENT = 0,
		HPDF_ANNOT_ICON_KEY,
		HPDF_ANNOT_ICON_NOTE,
		HPDF_ANNOT_ICON_HELP,
		HPDF_ANNOT_ICON_NEW_PARAGRAPH,
		HPDF_ANNOT_ICON_PARAGRAPH,
		HPDF_ANNOT_ICON_INSERT,
		HPDF_ANNOT_ICON_EOF
	} HPDF_AnnotIcon;

	typedef enum _HPDF_AnnotIntent {
		HPDF_ANNOT_INTENT_FREETEXTCALLOUT = 0,
		HPDF_ANNOT_INTENT_FREETEXTTYPEWRITER,
		HPDF_ANNOT_INTENT_LINEARROW,
		HPDF_ANNOT_INTENT_LINEDIMENSION,
		HPDF_ANNOT_INTENT_POLYGONCLOUD,
		HPDF_ANNOT_INTENT_POLYLINEDIMENSION,
		HPDF_ANNOT_INTENT_POLYGONDIMENSION
	} HPDF_AnnotIntent;

	typedef enum _HPDF_LineAnnotEndingStyle {
		HPDF_LINE_ANNOT_NONE = 0,
		HPDF_LINE_ANNOT_SQUARE,
		HPDF_LINE_ANNOT_CIRCLE,
		HPDF_LINE_ANNOT_DIAMOND,
		HPDF_LINE_ANNOT_OPENARROW,
		HPDF_LINE_ANNOT_CLOSEDARROW,
		HPDF_LINE_ANNOT_BUTT,
		HPDF_LINE_ANNOT_ROPENARROW,
		HPDF_LINE_ANNOT_RCLOSEDARROW,
		HPDF_LINE_ANNOT_SLASH
	} HPDF_LineAnnotEndingStyle;

	typedef enum _HPDF_LineAnnotCapPosition {
		HPDF_LINE_ANNOT_CAP_INLINE = 0,
		HPDF_LINE_ANNOT_CAP_TOP
	} HPDF_LineAnnotCapPosition;

	typedef enum _HPDF_StampAnnotName {
		HPDF_STAMP_ANNOT_APPROVED = 0,
		HPDF_STAMP_ANNOT_EXPERIMENTAL,
		HPDF_STAMP_ANNOT_NOTAPPROVED,
		HPDF_STAMP_ANNOT_ASIS,
		HPDF_STAMP_ANNOT_EXPIRED,
		HPDF_STAMP_ANNOT_NOTFORPUBLICRELEASE,
		HPDF_STAMP_ANNOT_CONFIDENTIAL,
		HPDF_STAMP_ANNOT_FINAL,
		HPDF_STAMP_ANNOT_SOLD,
		HPDF_STAMP_ANNOT_DEPARTMENTAL,
		HPDF_STAMP_ANNOT_FORCOMMENT,
		HPDF_STAMP_ANNOT_TOPSECRET,
		HPDF_STAMP_ANNOT_DRAFT,
		HPDF_STAMP_ANNOT_FORPUBLICRELEASE
	} HPDF_StampAnnotName;

	/*----------------------------------------------------------------------------*/
	/*------ border stype --------------------------------------------------------*/

	typedef enum _HPDF_BSSubtype {
		HPDF_BS_SOLID,
		HPDF_BS_DASHED,
		HPDF_BS_BEVELED,
		HPDF_BS_INSET,
		HPDF_BS_UNDERLINED
	} HPDF_BSSubtype;


	/*----- blend modes ----------------------------------------------------------*/

	typedef enum _HPDF_BlendMode {
		HPDF_BM_NORMAL,
		HPDF_BM_MULTIPLY,
		HPDF_BM_SCREEN,
		HPDF_BM_OVERLAY,
		HPDF_BM_DARKEN,
		HPDF_BM_LIGHTEN,
		HPDF_BM_COLOR_DODGE,
		HPDF_BM_COLOR_BUM,
		HPDF_BM_HARD_LIGHT,
		HPDF_BM_SOFT_LIGHT,
		HPDF_BM_DIFFERENCE,
		HPDF_BM_EXCLUSHON,
		HPDF_BM_EOF
	} HPDF_BlendMode;

	/*----- slide show -----------------------------------------------------------*/

	typedef enum _HPDF_TransitionStyle {
		HPDF_TS_WIPE_RIGHT = 0,
		HPDF_TS_WIPE_UP,
		HPDF_TS_WIPE_LEFT,
		HPDF_TS_WIPE_DOWN,
		HPDF_TS_BARN_DOORS_HORIZONTAL_OUT,
		HPDF_TS_BARN_DOORS_HORIZONTAL_IN,
		HPDF_TS_BARN_DOORS_VERTICAL_OUT,
		HPDF_TS_BARN_DOORS_VERTICAL_IN,
		HPDF_TS_BOX_OUT,
		HPDF_TS_BOX_IN,
		HPDF_TS_BLINDS_HORIZONTAL,
		HPDF_TS_BLINDS_VERTICAL,
		HPDF_TS_DISSOLVE,
		HPDF_TS_GLITTER_RIGHT,
		HPDF_TS_GLITTER_DOWN,
		HPDF_TS_GLITTER_TOP_LEFT_TO_BOTTOM_RIGHT,
		HPDF_TS_REPLACE,
		HPDF_TS_EOF
	} HPDF_TransitionStyle;

	/*----------------------------------------------------------------------------*/

	typedef enum _HPDF_PageSizes {
		HPDF_PAGE_SIZE_LETTER = 0,
		HPDF_PAGE_SIZE_LEGAL,
		HPDF_PAGE_SIZE_A3,
		HPDF_PAGE_SIZE_A4,
		HPDF_PAGE_SIZE_A5,
		HPDF_PAGE_SIZE_B4,
		HPDF_PAGE_SIZE_B5,
		HPDF_PAGE_SIZE_EXECUTIVE,
		HPDF_PAGE_SIZE_US4x6,
		HPDF_PAGE_SIZE_US4x8,
		HPDF_PAGE_SIZE_US5x7,
		HPDF_PAGE_SIZE_COMM10,
		HPDF_PAGE_SIZE_EOF
	} HPDF_PageSizes;


	typedef enum _HPDF_PageDirection {
		HPDF_PAGE_PORTRAIT = 0,
		HPDF_PAGE_LANDSCAPE
	} HPDF_PageDirection;


	typedef enum  _HPDF_EncoderType {
		HPDF_ENCODER_TYPE_SINGLE_BYTE,
		HPDF_ENCODER_TYPE_DOUBLE_BYTE,
		HPDF_ENCODER_TYPE_UNINITIALIZED,
		HPDF_ENCODER_UNKNOWN
	} HPDF_EncoderType;


	typedef enum _HPDF_ByteType {
		HPDF_BYTE_TYPE_SINGLE = 0,
		HPDF_BYTE_TYPE_LEAD,
		HPDF_BYTE_TYPE_TRIAL,
		HPDF_BYTE_TYPE_UNKNOWN
	} HPDF_ByteType;


	typedef enum _HPDF_TextAlignment {
		HPDF_TALIGN_LEFT = 0x00,
		HPDF_TALIGN_RIGHT = 0x02,
		HPDF_TALIGN_CENTER = 0x04,
		HPDF_TALIGN_JUSTIFY = 0x08,
		HPDF_TALIGN_TOP = 0x10,
		HPDF_TALIGN_BOTTOM = 0x20,
		HPDF_TALIGN_MIDDLE = 0x40
	} HPDF_TextAlignment;

	/*----------------------------------------------------------------------------*/

	/* Name Dictionary values -- see PDF reference section 7.7.4 */
	typedef enum _HPDF_NameDictKey {
		HPDF_NAME_EMBEDDED_FILES = 0,    /* TODO the rest */
		HPDF_NAME_EOF
	} HPDF_NameDictKey;

#endif /* _HPDF_TYPES_H */

#ifndef _HPDF_H
#define _HPDF_H

	typedef void         *HPDF_HANDLE;
	typedef HPDF_HANDLE   HPDF_Doc;
	typedef HPDF_HANDLE   HPDF_Page;
	typedef HPDF_HANDLE   HPDF_Pages;
	typedef HPDF_HANDLE   HPDF_Stream;
	typedef HPDF_HANDLE   HPDF_Image;
	typedef HPDF_HANDLE   HPDF_Font;
	typedef HPDF_HANDLE   HPDF_Outline;
	typedef HPDF_HANDLE   HPDF_Encoder;
	typedef HPDF_HANDLE   HPDF_3DMeasure;
	typedef HPDF_HANDLE   HPDF_ExData;
	typedef HPDF_HANDLE   HPDF_Destination;
	typedef HPDF_HANDLE   HPDF_XObject;
	typedef HPDF_HANDLE   HPDF_Annotation;
	typedef HPDF_HANDLE   HPDF_ExtGState;
	typedef HPDF_HANDLE   HPDF_FontDef;
	typedef HPDF_HANDLE   HPDF_U3D;
	typedef HPDF_HANDLE   HPDF_JavaScript;
	typedef HPDF_HANDLE   HPDF_Error;
	typedef HPDF_HANDLE   HPDF_MMgr;
	typedef HPDF_HANDLE   HPDF_Dict;
	typedef HPDF_HANDLE   HPDF_EmbeddedFile;
	typedef HPDF_HANDLE   HPDF_OutputIntent;
	typedef HPDF_HANDLE   HPDF_Xref;


	typedef const char * 
	(__stdcall* HPDF_GetVersion)(void);


	typedef HPDF_Doc
	(__stdcall* HPDF_NewEx)(HPDF_Error_Handler   user_error_fn,
							HPDF_Alloc_Func      user_alloc_fn,
							HPDF_Free_Func       user_free_fn,
							HPDF_UINT            mem_pool_buf_size,
							void                *user_data);

	typedef HPDF_Doc
	(__stdcall* HPDF_New)(HPDF_Error_Handler   user_error_fn,
						  void                *user_data);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SetErrorHandler)(HPDF_Doc            pdf,
									  HPDF_Error_Handler  user_error_fn);


	typedef void
	(__stdcall* HPDF_Free)(HPDF_Doc  pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_NewDoc)(HPDF_Doc  pdf);


	typedef void
	(__stdcall* HPDF_FreeDoc)(HPDF_Doc  pdf);


	typedef HPDF_BOOL
	(__stdcall* HPDF_HasDoc)(HPDF_Doc  pdf);


	typedef void
	(__stdcall* HPDF_FreeDocAll)(HPDF_Doc  pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SaveToStream)(HPDF_Doc   pdf);

	typedef HPDF_STATUS
	(__stdcall* HPDF_GetContents)(HPDF_Doc   pdf,
								  HPDF_BYTE  *buf,
								  HPDF_UINT32  *size);

	typedef HPDF_UINT32
	(__stdcall* HPDF_GetStreamSize)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_ReadFromStream)(HPDF_Doc       pdf,
									 HPDF_BYTE     *buf,
									 HPDF_UINT32   *size);


	typedef HPDF_STATUS
	(__stdcall* HPDF_ResetStream)(HPDF_Doc     pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SaveToFile)(HPDF_Doc     pdf,
								 const char  *file_name);


	typedef HPDF_STATUS
	(__stdcall* HPDF_GetError)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_GetErrorDetail)(HPDF_Doc   pdf);

	typedef void
	(__stdcall* HPDF_ResetError)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_CheckError)(HPDF_Error   error);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SetPagesConfiguration)(HPDF_Doc    pdf,
											HPDF_UINT   page_per_pages);


	typedef HPDF_Page
	(__stdcall* HPDF_GetPageByIndex)(HPDF_Doc    pdf,
									 HPDF_UINT   index);


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

	typedef HPDF_MMgr
	(__stdcall* HPDF_GetPageMMgr)(HPDF_Page  page);

	typedef HPDF_PageLayout
	(__stdcall* HPDF_GetPageLayout)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SetPageLayout)(HPDF_Doc          pdf,
									HPDF_PageLayout   layout);


	typedef HPDF_PageMode
	(__stdcall* HPDF_GetPageMode)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SetPageMode)(HPDF_Doc        pdf,
								  HPDF_PageMode   mode);


	typedef HPDF_UINT
	(__stdcall* HPDF_GetViewerPreference)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SetViewerPreference)(HPDF_Doc     pdf,
										  HPDF_UINT    value);


	typedef HPDF_STATUS
	(__stdcall* HPDF_SetOpenAction)(HPDF_Doc           pdf,
									HPDF_Destination   open_action);


/*---------------------------------------------------------------------------*/
/*----- page handling -------------------------------------------------------*/


	typedef HPDF_Page
	(__stdcall* HPDF_GetCurrentPage)(HPDF_Doc  pdf);


	typedef HPDF_Page
	(__stdcall* HPDF_AddPage)(HPDF_Doc   pdf);


	typedef HPDF_Page
	(__stdcall* HPDF_InsertPage)(HPDF_Doc    pdf,
								 HPDF_Page   page);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Page_SetWidth)(HPDF_Page   page,
									HPDF_REAL   value);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Page_SetHeight)(HPDF_Page   page,
									 HPDF_REAL   value);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Page_SetSize)(HPDF_Page            page,
							  	  HPDF_PageSizes       size,
								  HPDF_PageDirection   direction);

	typedef HPDF_STATUS
	(__stdcall* HPDF_Page_SetRotate)(HPDF_Page     page,
									HPDF_UINT16   angle);

	typedef HPDF_STATUS
	(__stdcall* HPDF_Page_SetZoom)(HPDF_Page     page,
								  HPDF_REAL     zoom);

/*---------------------------------------------------------------------------*/
/*----- font handling -------------------------------------------------------*/


	typedef HPDF_Font
	(__stdcall* HPDF_GetFont)(HPDF_Doc     pdf,
							  const char  *font_name,
							  const char  *encoding_name);


	typedef const char*
	(__stdcall* HPDF_LoadType1FontFromFile)(HPDF_Doc     pdf,
										    const char  *afm_file_name,
										    const char  *data_file_name);


	typedef HPDF_FontDef
	(__stdcall* HPDF_GetTTFontDefFromFile)(HPDF_Doc     pdf,
										   const char  *file_name,
										   HPDF_BOOL    embedding);

	typedef const char*
	(__stdcall* HPDF_LoadTTFontFromFile)(HPDF_Doc     pdf,
										 const char  *file_name,
										 HPDF_BOOL    embedding);


	typedef const char*
	(__stdcall* HPDF_LoadTTFontFromFile2)(HPDF_Doc     pdf,
										  const char  *file_name,
										  HPDF_UINT    index,
										  HPDF_BOOL    embedding);


	typedef HPDF_STATUS
	(__stdcall* HPDF_AddPageLabel)(HPDF_Doc            pdf,
								   HPDF_UINT           page_num,
								   HPDF_PageNumStyle   style,
								   HPDF_UINT           first_page,
								   const char         *prefix);


	typedef HPDF_STATUS
	(__stdcall* HPDF_UseJPFonts)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_UseKRFonts)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_UseCNSFonts)(HPDF_Doc   pdf);


	typedef HPDF_STATUS
	(__stdcall* HPDF_UseCNTFonts)(HPDF_Doc   pdf);


/*--------------------------------------------------------------------------*/
/*----- outline ------------------------------------------------------------*/


	typedef HPDF_Outline
	(__stdcall* HPDF_CreateOutline)(HPDF_Doc       pdf,
								    HPDF_Outline   parent,
								    const char    *title,
								    HPDF_Encoder   encoder);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Outline_SetOpened)(HPDF_Outline  outline,
									   HPDF_BOOL     opened);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Outline_SetDestination)(HPDF_Outline      outline,
											 HPDF_Destination  dst);


/*--------------------------------------------------------------------------*/
/*----- destination --------------------------------------------------------*/

	typedef HPDF_Destination
	(__stdcall* HPDF_Page_CreateDestination)(HPDF_Page   page);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetXYZ)(HPDF_Destination  dst,
										 HPDF_REAL         left,
										 HPDF_REAL         top,
										 HPDF_REAL         zoom);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetFit)(HPDF_Destination  dst);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetFitH)(HPDF_Destination  dst,
										  HPDF_REAL         top);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetFitV)(HPDF_Destination  dst,
										  HPDF_REAL         left);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetFitR)(HPDF_Destination  dst,
										  HPDF_REAL         left,
										  HPDF_REAL         bottom,
										  HPDF_REAL         right,
										  HPDF_REAL         top);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetFitB)(HPDF_Destination  dst);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetFitBH)(HPDF_Destination  dst,
										   HPDF_REAL         top);


	typedef HPDF_STATUS
	(__stdcall* HPDF_Destination_SetFitBV)(HPDF_Destination  dst,
										  HPDF_REAL         left);

/*--------------------------------------------------------------------------*/
/*----- encoder ------------------------------------------------------------*/

		/*typedef HPDF_Encoder)
			HPDF_GetEncoder(HPDF_Doc     pdf,
				const char  *encoding_name);


		typedef HPDF_Encoder)
			HPDF_GetCurrentEncoder(HPDF_Doc   pdf);


		typedef HPDF_STATUS)
			HPDF_SetCurrentEncoder(HPDF_Doc     pdf,
				const char  *encoding_name);


		typedef HPDF_EncoderType)
			HPDF_Encoder_GetType(HPDF_Encoder   encoder);


		typedef HPDF_ByteType)
			HPDF_Encoder_GetByteType(HPDF_Encoder    encoder,
				const char     *text,
				HPDF_UINT       index);


		typedef HPDF_UNICODE)
			HPDF_Encoder_GetUnicode(HPDF_Encoder   encoder,
				HPDF_UINT16    code);


		typedef HPDF_WritingMode)
			HPDF_Encoder_GetWritingMode(HPDF_Encoder   encoder);


		typedef HPDF_STATUS)
			HPDF_UseJPEncodings(HPDF_Doc   pdf);



		typedef HPDF_STATUS)
			HPDF_UseKREncodings(HPDF_Doc   pdf);



		typedef HPDF_STATUS)
			HPDF_UseCNSEncodings(HPDF_Doc   pdf);



		typedef HPDF_STATUS)
			HPDF_UseCNTEncodings(HPDF_Doc   pdf);


		typedef HPDF_STATUS)
			HPDF_UseUTFEncodings(HPDF_Doc   pdf);*/


/*--------------------------------------------------------------------------*/
/*----- XObject ------------------------------------------------------------*/

		//typedef HPDF_XObject)
		//	HPDF_Page_CreateXObjectFromImage(HPDF_Doc       pdf,
		//		HPDF_Page      page,
		//		HPDF_Rect      rect,
		//		HPDF_Image     image,
		//		HPDF_BOOL   zoom);

		//typedef HPDF_XObject)
		//	HPDF_Page_CreateXObjectAsWhiteRect(HPDF_Doc   pdf,
		//		HPDF_Page  page,
		//		HPDF_Rect  rect);

/*--------------------------------------------------------------------------*/
/*----- annotation ---------------------------------------------------------*/

		//typedef HPDF_Annotation)
		//	HPDF_Page_Create3DAnnot(HPDF_Page       page,
		//		HPDF_Rect       rect,
		//		HPDF_BOOL       tb,
		//		HPDF_BOOL       np,
		//		HPDF_U3D        u3d,
		//		HPDF_Image      ap);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateTextAnnot(HPDF_Page       page,
		//		HPDF_Rect       rect,
		//		const char     *text,
		//		HPDF_Encoder    encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateFreeTextAnnot(HPDF_Page       page,
		//		HPDF_Rect       rect,
		//		const char     *text,
		//		HPDF_Encoder    encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateLineAnnot(HPDF_Page       page,
		//		const char     *text,
		//		HPDF_Encoder    encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateWidgetAnnot_WhiteOnlyWhilePrint(HPDF_Doc   pdf,
		//		HPDF_Page  page,
		//		HPDF_Rect  rect);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateWidgetAnnot(HPDF_Page  page,
		//		HPDF_Rect  rect);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateLinkAnnot(HPDF_Page          page,
		//		HPDF_Rect          rect,
		//		HPDF_Destination   dst);


		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateURILinkAnnot(HPDF_Page     page,
		//		HPDF_Rect     rect,
		//		const char   *uri);


		//HPDF_Annotation
		//	HPDF_Page_CreateTextMarkupAnnot(HPDF_Page     page,
		//		HPDF_Rect      rect,
		//		const char     *text,
		//		HPDF_Encoder   encoder,
		//		HPDF_AnnotType subType);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateHighlightAnnot(HPDF_Page   page,
		//		HPDF_Rect    rect,
		//		const char   *text,
		//		HPDF_Encoder encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateUnderlineAnnot(HPDF_Page    page,
		//		HPDF_Rect    rect,
		//		const char   *text,
		//		HPDF_Encoder encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateSquigglyAnnot(HPDF_Page    page,
		//		HPDF_Rect    rect,
		//		const char   *text,
		//		HPDF_Encoder encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateStrikeOutAnnot(HPDF_Page   page,
		//		HPDF_Rect    rect,
		//		const char   *text,
		//		HPDF_Encoder encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreatePopupAnnot(HPDF_Page          page,
		//		HPDF_Rect          rect,
		//		HPDF_Annotation	   parent);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateStampAnnot(HPDF_Page           page,
		//		HPDF_Rect           rect,
		//		HPDF_StampAnnotName name,
		//		const char*			text,
		//		HPDF_Encoder		encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateProjectionAnnot(HPDF_Page page,
		//		HPDF_Rect rect,
		//		const char* text,
		//		HPDF_Encoder encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateSquareAnnot(HPDF_Page          page,
		//		HPDF_Rect          rect,
		//		const char			*text,
		//		HPDF_Encoder       encoder);

		//typedef HPDF_Annotation)
		//	HPDF_Page_CreateCircleAnnot(HPDF_Page          page,
		//		HPDF_Rect          rect,
		//		const char			*text,
		//		HPDF_Encoder       encoder);

		//typedef HPDF_STATUS)
		//	HPDF_LinkAnnot_SetHighlightMode(HPDF_Annotation           annot,
		//		HPDF_AnnotHighlightMode   mode);

		//typedef HPDF_STATUS)
		//	HPDF_LinkAnnot_SetJavaScript(HPDF_Annotation    annot,
		//		HPDF_JavaScript    javascript);

		//typedef HPDF_STATUS)
		//	HPDF_LinkAnnot_SetBorderStyle(HPDF_Annotation  annot,
		//		HPDF_REAL        width,
		//		HPDF_UINT16      dash_on,
		//		HPDF_UINT16      dash_off);


		//typedef HPDF_STATUS)
		//	HPDF_TextAnnot_SetIcon(HPDF_Annotation   annot,
		//		HPDF_AnnotIcon    icon);


		//typedef HPDF_STATUS)
		//	HPDF_TextAnnot_SetOpened(HPDF_Annotation   annot,
		//		HPDF_BOOL          opened);

		//typedef HPDF_STATUS)
		//	HPDF_Annot_SetRGBColor(HPDF_Annotation annot, HPDF_RGBColor color);

		//typedef HPDF_STATUS)
		//	HPDF_Annot_SetCMYKColor(HPDF_Annotation annot, HPDF_CMYKColor color);

		//typedef HPDF_STATUS)
		//	HPDF_Annot_SetGrayColor(HPDF_Annotation annot, HPDF_REAL color);

		//typedef HPDF_STATUS)
		//	HPDF_Annot_SetNoColor(HPDF_Annotation annot);

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetTitle(HPDF_Annotation annot, const char* name);

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetSubject(HPDF_Annotation annot, const char* name);

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetCreationDate(HPDF_Annotation annot, HPDF_Date value);

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetTransparency(HPDF_Annotation annot, HPDF_REAL value);

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetIntent(HPDF_Annotation  annot, HPDF_AnnotIntent  intent);

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetPopup(HPDF_Annotation annot, HPDF_Annotation popup);

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetRectDiff(HPDF_Annotation  annot, HPDF_Rect  rect); /* RD entry */

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetCloudEffect(HPDF_Annotation  annot, HPDF_INT cloudIntensity); /* BE entry */

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetInteriorRGBColor(HPDF_Annotation  annot, HPDF_RGBColor color); /* IC with RGB entry */

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetInteriorCMYKColor(HPDF_Annotation  annot, HPDF_CMYKColor color); /* IC with CMYK entry */

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetInteriorGrayColor(HPDF_Annotation  annot, HPDF_REAL color); /* IC with Gray entry */

		//typedef HPDF_STATUS)
		//	HPDF_MarkupAnnot_SetInteriorTransparent(HPDF_Annotation  annot); /* IC with No Color entry */

		//typedef HPDF_STATUS)
		//	HPDF_TextMarkupAnnot_SetQuadPoints(HPDF_Annotation annot, HPDF_Point lb, HPDF_Point rb, HPDF_Point rt, HPDF_Point lt); /* l-left, r-right, b-bottom, t-top positions */

		//typedef HPDF_STATUS)
		//	HPDF_Annot_Set3DView(HPDF_MMgr mmgr,
		//		HPDF_Annotation	annot,
		//		HPDF_Annotation	annot3d,
		//		HPDF_Dict			view);

		//typedef HPDF_STATUS)
		//	HPDF_PopupAnnot_SetOpened(HPDF_Annotation   annot,
		//		HPDF_BOOL         opened);

		//typedef HPDF_STATUS)
		//	HPDF_FreeTextAnnot_SetLineEndingStyle(HPDF_Annotation annot, HPDF_LineAnnotEndingStyle startStyle, HPDF_LineAnnotEndingStyle endStyle);

		//typedef HPDF_STATUS)
		//	HPDF_FreeTextAnnot_Set3PointCalloutLine(HPDF_Annotation annot, HPDF_Point startPoint, HPDF_Point kneePoint, HPDF_Point endPoint); /* Callout line will be in default user space */

		//typedef HPDF_STATUS)
		//	HPDF_FreeTextAnnot_Set2PointCalloutLine(HPDF_Annotation annot, HPDF_Point startPoint, HPDF_Point endPoint); /* Callout line will be in default user space */

		//typedef HPDF_STATUS)
		//	HPDF_FreeTextAnnot_SetDefaultStyle(HPDF_Annotation  annot, const char* style);

		//typedef HPDF_STATUS)
		//	HPDF_LineAnnot_SetPosition(HPDF_Annotation annot,
		//		HPDF_Point startPoint, HPDF_LineAnnotEndingStyle startStyle,
		//		HPDF_Point endPoint, HPDF_LineAnnotEndingStyle endStyle);

		//typedef HPDF_STATUS)
		//	HPDF_LineAnnot_SetLeader(HPDF_Annotation annot, HPDF_INT leaderLen, HPDF_INT leaderExtLen, HPDF_INT leaderOffsetLen);

		//typedef HPDF_STATUS)
		//	HPDF_LineAnnot_SetCaption(HPDF_Annotation annot, HPDF_BOOL showCaption, HPDF_LineAnnotCapPosition position, HPDF_INT horzOffset, HPDF_INT vertOffset);

		//typedef HPDF_STATUS)
		//	HPDF_Annotation_SetBorderStyle(HPDF_Annotation  annot,
		//		HPDF_BSSubtype   subtype,
		//		HPDF_REAL        width,
		//		HPDF_UINT16      dash_on,
		//		HPDF_UINT16      dash_off,
		//		HPDF_UINT16      dash_phase);

		//typedef HPDF_STATUS)
		//	HPDF_ProjectionAnnot_SetExData(HPDF_Annotation annot, HPDF_ExData exdata);


/*--------------------------------------------------------------------------*/
/*----- 3D Measure ---------------------------------------------------------*/
		
//typedef HPDF_3DMeasure)
//			HPDF_Page_Create3DC3DMeasure(HPDF_Page       page,
//				HPDF_Point3D    firstanchorpoint,
//				HPDF_Point3D    textanchorpoint
//			);
//
//		typedef HPDF_3DMeasure)
//			HPDF_Page_CreatePD33DMeasure(HPDF_Page       page,
//				HPDF_Point3D    annotationPlaneNormal,
//				HPDF_Point3D    firstAnchorPoint,
//				HPDF_Point3D    secondAnchorPoint,
//				HPDF_Point3D    leaderLinesDirection,
//				HPDF_Point3D    measurementValuePoint,
//				HPDF_Point3D    textYDirection,
//				HPDF_REAL       value,
//				const char*     unitsString
//			);
//
//		typedef HPDF_STATUS)
//			HPDF_3DMeasure_SetName(HPDF_3DMeasure measure,
//				const char* name);
//
//		typedef HPDF_STATUS)
//			HPDF_3DMeasure_SetColor(HPDF_3DMeasure measure,
//				HPDF_RGBColor color);
//
//		typedef HPDF_STATUS)
//			HPDF_3DMeasure_SetTextSize(HPDF_3DMeasure measure,
//				HPDF_REAL textsize);
//
//		typedef HPDF_STATUS)
//			HPDF_3DC3DMeasure_SetTextBoxSize(HPDF_3DMeasure measure,
//				HPDF_INT32 x,
//				HPDF_INT32 y);
//
//		typedef HPDF_STATUS)
//			HPDF_3DC3DMeasure_SetText(HPDF_3DMeasure measure,
//				const char* text,
//				HPDF_Encoder encoder);
//
//		typedef HPDF_STATUS)
//			HPDF_3DC3DMeasure_SetProjectionAnotation(HPDF_3DMeasure measure,
//				HPDF_Annotation projectionanotation);

/*--------------------------------------------------------------------------*/
/*----- External Data ---------------------------------------------------------*/

typedef HPDF_ExData
(__stdcall* HPDF_Page_Create3DAnnotExData)(HPDF_Page       page);

typedef HPDF_STATUS
(__stdcall* HPDF_3DAnnotExData_Set3DMeasurement)(HPDF_ExData exdata, HPDF_3DMeasure measure);

/*--------------------------------------------------------------------------*/
/*----- 3D View ---------------------------------------------------------*/

typedef HPDF_Dict
(__stdcall* HPDF_Page_Create3DView)(HPDF_Page       page,
									HPDF_U3D        u3d,
									HPDF_Annotation	annot3d,
									const char *name);

typedef HPDF_STATUS
(__stdcall* HPDF_3DView_Add3DC3DMeasure)(HPDF_Dict       view,
										 HPDF_3DMeasure measure);

/*--------------------------------------------------------------------------*/
/*----- image data ---------------------------------------------------------*/

		/*typedef HPDF_Image)
			HPDF_LoadPngImageFromMem(HPDF_Doc     pdf,
				const HPDF_BYTE    *buffer,
				HPDF_UINT     size);

		typedef HPDF_Image)
			HPDF_LoadPngImageFromFile(HPDF_Doc      pdf,
				const char    *filename);


		typedef HPDF_Image)
			HPDF_LoadPngImageFromFile2(HPDF_Doc      pdf,
				const char    *filename);


		typedef HPDF_Image)
			HPDF_LoadJpegImageFromFile(HPDF_Doc      pdf,
				const char    *filename);

		typedef HPDF_Image)
			HPDF_LoadJpegImageFromMem(HPDF_Doc      pdf,
				const HPDF_BYTE     *buffer,
				HPDF_UINT      size);

		typedef HPDF_Image)
			HPDF_LoadU3DFromFile(HPDF_Doc      pdf,
				const char    *filename);

		typedef HPDF_Image)
			HPDF_LoadU3DFromMem(HPDF_Doc      pdf,
				const HPDF_BYTE     *buffer,
				HPDF_UINT      size);

		typedef HPDF_Image)
			HPDF_Image_LoadRaw1BitImageFromMem(HPDF_Doc           pdf,
				const HPDF_BYTE   *buf,
				HPDF_UINT          width,
				HPDF_UINT          height,
				HPDF_UINT          line_width,
				HPDF_BOOL          black_is1,
				HPDF_BOOL          top_is_first);


		typedef HPDF_Image)
			HPDF_LoadRawImageFromFile(HPDF_Doc           pdf,
				const char         *filename,
				HPDF_UINT          width,
				HPDF_UINT          height,
				HPDF_ColorSpace    color_space);


		typedef HPDF_Image)
			HPDF_LoadRawImageFromMem(HPDF_Doc           pdf,
				const HPDF_BYTE   *buf,
				HPDF_UINT          width,
				HPDF_UINT          height,
				HPDF_ColorSpace    color_space,
				HPDF_UINT          bits_per_component);

		typedef HPDF_STATUS)
			HPDF_Image_AddSMask(HPDF_Image    image,
				HPDF_Image    smask);

		typedef HPDF_Point)
			HPDF_Image_GetSize(HPDF_Image  image);


		typedef HPDF_STATUS)
			HPDF_Image_GetSize2(HPDF_Image  image, HPDF_Point *size);


		typedef HPDF_UINT)
			HPDF_Image_GetWidth(HPDF_Image   image);


		typedef HPDF_UINT)
			HPDF_Image_GetHeight(HPDF_Image   image);


		typedef HPDF_UINT)
			HPDF_Image_GetBitsPerComponent(HPDF_Image  image);


		typedef const char*)
			HPDF_Image_GetColorSpace(HPDF_Image  image);


		typedef HPDF_STATUS)
			HPDF_Image_SetColorMask(HPDF_Image   image,
				HPDF_UINT    rmin,
				HPDF_UINT    rmax,
				HPDF_UINT    gmin,
				HPDF_UINT    gmax,
				HPDF_UINT    bmin,
				HPDF_UINT    bmax);


		typedef HPDF_STATUS)
			HPDF_Image_SetMaskImage(HPDF_Image   image,
				HPDF_Image   mask_image);*/


/*--------------------------------------------------------------------------*/
/*----- info dictionary ----------------------------------------------------*/


typedef HPDF_STATUS
(__stdcall* HPDF_SetInfoAttr)(HPDF_Doc        pdf,
							  HPDF_InfoType   type,
							  const char     *value);


typedef const char*
(__stdcall* HPDF_GetInfoAttr)(HPDF_Doc        pdf,
							  HPDF_InfoType   type);


typedef HPDF_STATUS
(__stdcall* HPDF_SetInfoDateAttr)(HPDF_Doc        pdf,
								  HPDF_InfoType   type,
								  HPDF_Date       value);


/*--------------------------------------------------------------------------*/
/*----- encryption ---------------------------------------------------------*/

typedef HPDF_STATUS
(__stdcall* HPDF_SetPassword)(HPDF_Doc      pdf,
							  const char   *owner_passwd,
							  const char   *user_passwd);


typedef HPDF_STATUS
(__stdcall* HPDF_SetPermission)(HPDF_Doc    pdf,
							   HPDF_UINT   permission);


typedef HPDF_STATUS
(__stdcall* HPDF_SetEncryptionMode)(HPDF_Doc           pdf,
									HPDF_EncryptMode   mode,
									HPDF_UINT          key_len);

/*--------------------------------------------------------------------------*/
/*----- compression --------------------------------------------------------*/

typedef HPDF_STATUS
(__stdcall* HPDF_SetCompressionMode)(HPDF_Doc    pdf,
									 HPDF_UINT   mode);

/*--------------------------------------------------------------------------*/
/*----- font ---------------------------------------------------------------*/

typedef const char*
(__stdcall* HPDF_Font_GetFontName)(HPDF_Font    font);


typedef const char*
(__stdcall* HPDF_Font_GetEncodingName)(HPDF_Font    font);


typedef HPDF_INT
(__stdcall* HPDF_Font_GetUnicodeWidth)(HPDF_Font       font,
									  HPDF_UNICODE    code);

typedef HPDF_Box
(__stdcall* HPDF_Font_GetBBox)(HPDF_Font    font);


typedef HPDF_INT
(__stdcall* HPDF_Font_GetAscent)(HPDF_Font  font);


typedef HPDF_INT
(__stdcall* HPDF_Font_GetDescent)(HPDF_Font  font);


typedef HPDF_UINT
(__stdcall* HPDF_Font_GetXHeight)(HPDF_Font  font);


typedef HPDF_UINT
(__stdcall* HPDF_Font_GetCapHeight)(HPDF_Font  font);


typedef HPDF_TextWidth
(__stdcall* HPDF_Font_TextWidth)(HPDF_Font          font,
								 const HPDF_BYTE   *text,
								 HPDF_UINT          len);


typedef HPDF_UINT
(__stdcall* HPDF_Font_MeasureText)(HPDF_Font          font,
								   const HPDF_BYTE   *text,
								   HPDF_UINT          len,
								   HPDF_REAL          width,
								   HPDF_REAL          font_size,
								   HPDF_REAL          char_space,
								   HPDF_REAL          word_space,
								   HPDF_BOOL          wordwrap,
								   HPDF_REAL         *real_width);

/*--------------------------------------------------------------------------*/
/*----- attachements -------------------------------------------------------*/

		typedef HPDF_EmbeddedFile
		(__stdcall*	HPDF_AttachFile)(HPDF_Doc    pdf,
									 const char *file);

/*--------------------------------------------------------------------------*/
/*----- extended graphics state --------------------------------------------*/

		typedef HPDF_ExtGState
		(__stdcall* HPDF_CreateExtGState)(HPDF_Doc  pdf);


		typedef HPDF_STATUS
		(__stdcall*	HPDF_ExtGState_SetAlphaStroke)(HPDF_ExtGState   ext_gstate,
												  HPDF_REAL        value);


		typedef HPDF_STATUS
		(__stdcall*	HPDF_ExtGState_SetAlphaFill)(HPDF_ExtGState   ext_gstate,
												 HPDF_REAL        value);


		typedef HPDF_STATUS
		(__stdcall*	HPDF_ExtGState_SetBlendMode)(HPDF_ExtGState   ext_gstate,
												HPDF_BlendMode   mode);


/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

typedef HPDF_REAL
(__stdcall*	HPDF_Page_TextWidth)(HPDF_Page    page,
								 const char  *text);


typedef HPDF_UINT
(__stdcall* HPDF_Page_MeasureText)(HPDF_Page    page,
								   const char  *text,
								   HPDF_REAL    width,
								   HPDF_BOOL    wordwrap,
								   HPDF_REAL   *real_width);

typedef HPDF_REAL
(__stdcall*	HPDF_Page_GetWidth)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetHeight)(HPDF_Page   page);


typedef HPDF_UINT16
(__stdcall* HPDF_Page_GetGMode)(HPDF_Page   page);


typedef HPDF_Point
(__stdcall* HPDF_Page_GetCurrentPos)(HPDF_Page   page);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_GetCurrentPos2)(HPDF_Page    page,
									  HPDF_Point  *pos);


typedef HPDF_Point
(__stdcall* HPDF_Page_GetCurrentTextPos)(HPDF_Page   page);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_GetCurrentTextPos2)(HPDF_Page    page,
										 HPDF_Point  *pos);


typedef HPDF_Font
(__stdcall* HPDF_Page_GetCurrentFont)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetCurrentFontSize)(HPDF_Page   page);


typedef HPDF_TransMatrix
(__stdcall* HPDF_Page_GetTransMatrix)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetLineWidth)(HPDF_Page   page);


typedef HPDF_LineCap
(__stdcall* HPDF_Page_GetLineCap)(HPDF_Page   page);


typedef HPDF_LineJoin
(__stdcall* HPDF_Page_GetLineJoin)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetMiterLimit)(HPDF_Page   page);


typedef HPDF_DashMode
(__stdcall* HPDF_Page_GetDash)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetFlat)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetCharSpace)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetWordSpace)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetHorizontalScalling)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetTextLeading)(HPDF_Page   page);


typedef HPDF_TextRenderingMode
(__stdcall* HPDF_Page_GetTextRenderingMode)(HPDF_Page   page);


/* This function is obsolete. Use HPDF_Page_GetTextRise.  */
typedef HPDF_REAL
(__stdcall* HPDF_Page_GetTextRaise)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetTextRise)(HPDF_Page   page);


typedef HPDF_RGBColor
(__stdcall* HPDF_Page_GetRGBFill)(HPDF_Page   page);


typedef HPDF_RGBColor
(__stdcall* HPDF_Page_GetRGBStroke)(HPDF_Page   page);


typedef HPDF_CMYKColor
(__stdcall* HPDF_Page_GetCMYKFill)(HPDF_Page   page);


typedef HPDF_CMYKColor
(__stdcall* HPDF_Page_GetCMYKStroke)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetGrayFill)(HPDF_Page   page);


typedef HPDF_REAL
(__stdcall* HPDF_Page_GetGrayStroke)(HPDF_Page   page);


typedef HPDF_ColorSpace
(__stdcall* HPDF_Page_GetStrokingColorSpace)(HPDF_Page   page);


typedef HPDF_ColorSpace
(__stdcall* HPDF_Page_GetFillingColorSpace)(HPDF_Page   page);


typedef HPDF_TransMatrix
(__stdcall* HPDF_Page_GetTextMatrix)(HPDF_Page   page);


typedef HPDF_UINT
(__stdcall* HPDF_Page_GetGStateDepth)(HPDF_Page   page);


/*--------------------------------------------------------------------------*/
/*----- GRAPHICS OPERATORS -------------------------------------------------*/


/*--- General graphics state ---------------------------------------------*/

		/* w */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetLineWidth(HPDF_Page  page,
		//		HPDF_REAL  line_width);

		///* J */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetLineCap(HPDF_Page     page,
		//		HPDF_LineCap  line_cap);

		///* j */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetLineJoin(HPDF_Page      page,
		//		HPDF_LineJoin  line_join);

		///* M */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetMiterLimit(HPDF_Page  page,
		//		HPDF_REAL  miter_limit);

		///* d */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetDash(HPDF_Page           page,
		//		const HPDF_UINT16  *dash_ptn,
		//		HPDF_UINT           num_param,
		//		HPDF_UINT           phase);



		///* ri --not implemented yet */

		///* i */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetFlat(HPDF_Page    page,
		//		HPDF_REAL    flatness);

		///* gs */

		//typedef HPDF_STATUS)
		//	HPDF_Page_SetExtGState(HPDF_Page        page,
		//		HPDF_ExtGState   ext_gstate);


		/*--- Special graphic state operator --------------------------------------*/

		/* q */
		//typedef HPDF_STATUS)
		//	HPDF_Page_GSave(HPDF_Page    page);

		///* Q */
		//typedef HPDF_STATUS)
		//	HPDF_Page_GRestore(HPDF_Page    page);

		///* cm */
		//typedef HPDF_STATUS)
		//	HPDF_Page_Concat(HPDF_Page    page,
		//		HPDF_REAL    a,
		//		HPDF_REAL    b,
		//		HPDF_REAL    c,
		//		HPDF_REAL    d,
		//		HPDF_REAL    x,
		//		HPDF_REAL    y);

/*--- Path construction operator ------------------------------------------*/

/* m */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_MoveTo)(HPDF_Page    page,
							  HPDF_REAL    x,
							  HPDF_REAL    y);

/* l */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_LineTo)(HPDF_Page    page,
							  HPDF_REAL    x,
							  HPDF_REAL    y);

/* c */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_CurveTo)(HPDF_Page    page,
							   HPDF_REAL    x1,
							   HPDF_REAL    y1,
							   HPDF_REAL    x2,
							   HPDF_REAL    y2,
							   HPDF_REAL    x3,
							   HPDF_REAL    y3);

/* v */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_CurveTo2)(HPDF_Page    page,
								HPDF_REAL    x2,
								HPDF_REAL    y2,
								HPDF_REAL    x3,
								HPDF_REAL    y3);

/* y */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_CurveTo3)(HPDF_Page  page,
								HPDF_REAL  x1,
								HPDF_REAL  y1,
								HPDF_REAL  x3,
								HPDF_REAL  y3);

/* h */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ClosePath)(HPDF_Page  page);

/* re */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_Rectangle)(HPDF_Page  page,
								 HPDF_REAL  x,
								 HPDF_REAL  y,
								 HPDF_REAL  width,
								 HPDF_REAL  height);


/*--- Path painting operator ---------------------------------------------*/

/* S */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_Stroke)(HPDF_Page  page);

/* s */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ClosePathStroke)(HPDF_Page  page);

/* f */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_Fill)(HPDF_Page  page);

/* f* */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_Eofill)(HPDF_Page  page);

/* B */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_FillStroke)(HPDF_Page  page);

/* B* */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_EofillStroke)(HPDF_Page  page);

/* b */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ClosePathFillStroke)(HPDF_Page  page);

/* b */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ClosePathEofillStroke)(HPDF_Page  page);

/* n */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_EndPath)(HPDF_Page  page);


/*--- Clipping paths operator --------------------------------------------*/

		/* W */
		//typedef HPDF_STATUS)
		//	HPDF_Page_Clip(HPDF_Page  page);

		///* W* */
		//typedef HPDF_STATUS)
		//	HPDF_Page_Eoclip(HPDF_Page  page);


/*--- Text object operator -----------------------------------------------*/

/* BT */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_BeginText)(HPDF_Page  page);

/* ET */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_EndText)(HPDF_Page  page);

/*--- Text state ---------------------------------------------------------*/

/* Tc */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetCharSpace)(HPDF_Page  page,
									HPDF_REAL  value);

/* Tw */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetWordSpace)(HPDF_Page  page,
								    HPDF_REAL  value);

/* Tz */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetHorizontalScalling)(HPDF_Page  page,
											 HPDF_REAL  value);

/* TL */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetTextLeading)(HPDF_Page  page,
									  HPDF_REAL  value);

/* Tf */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetFontAndSize)(HPDF_Page  page,
									  HPDF_Font  font,
									  HPDF_REAL  size);

/* Tr */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetTextRenderingMode)(HPDF_Page               page,
										   HPDF_TextRenderingMode  mode);

/* Ts */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetTextRise)(HPDF_Page   page,
								  HPDF_REAL   value);

/* This function is obsolete. Use HPDF_Page_SetTextRise.  */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetTextRaise)(HPDF_Page   page,
									HPDF_REAL   value);

/*--- Text positioning ---------------------------------------------------*/

/* Td */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_MoveTextPos)(HPDF_Page   page,
								  HPDF_REAL   x,
								  HPDF_REAL   y);

/* TD */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_MoveTextPos2)(HPDF_Page  page,
								   HPDF_REAL   x,
								   HPDF_REAL   y);

/* Tm */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetTextMatrix)(HPDF_Page         page,
									 HPDF_REAL    a,
									 HPDF_REAL    b,
									 HPDF_REAL    c,
									 HPDF_REAL    d,
									 HPDF_REAL    x,
									 HPDF_REAL    y);


/* T* */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_MoveToNextLine)(HPDF_Page  page);

/*--- Text showing -------------------------------------------------------*/

/* Tj */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ShowText)(HPDF_Page    page,
								const char  *text);

/* TJ */

/* ' */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ShowTextNextLine)(HPDF_Page    page,
									   const char  *text);

/* " */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ShowTextNextLineEx)(HPDF_Page    page,
										  HPDF_REAL    word_space,
										  HPDF_REAL    char_space,
										  const char  *text);


/*--- Color showing ------------------------------------------------------*/

/* cs --not implemented yet */
/* CS --not implemented yet */
/* sc --not implemented yet */
/* scn --not implemented yet */
/* SC --not implemented yet */
/* SCN --not implemented yet */

		/* g */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetGrayFill(HPDF_Page   page,
		//		HPDF_REAL   gray);

		/* G */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetGrayStroke(HPDF_Page   page,
		//		HPDF_REAL   gray);

		/* rg */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetRGBFill(HPDF_Page  page,
		//		HPDF_REAL  r,
		//		HPDF_REAL  g,
		//		HPDF_REAL  b);

		/* RG */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetRGBStroke(HPDF_Page  page,
		//		HPDF_REAL  r,
		//		HPDF_REAL  g,
		//		HPDF_REAL  b);

		/* k */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetCMYKFill(HPDF_Page  page,
		//		HPDF_REAL  c,
		//		HPDF_REAL  m,
		//		HPDF_REAL  y,
		//		HPDF_REAL  k);

		/* K */
		//typedef HPDF_STATUS)
		//	HPDF_Page_SetCMYKStroke(HPDF_Page  page,
		//		HPDF_REAL  c,
		//		HPDF_REAL  m,
		//		HPDF_REAL  y,
		//		HPDF_REAL  k);

/*--- Shading patterns ---------------------------------------------------*/

/* sh --not implemented yet */

/*--- In-line images -----------------------------------------------------*/

/* BI --not implemented yet */
/* ID --not implemented yet */
/* EI --not implemented yet */

/*--- XObjects -----------------------------------------------------------*/

/* Do */
typedef HPDF_STATUS
(__stdcall* HPDF_Page_ExecuteXObject)(HPDF_Page     page,
									  HPDF_XObject  obj);

/*--- Content streams ----------------------------------------------------*/

typedef HPDF_STATUS
(__stdcall* HPDF_Page_New_Content_Stream)(HPDF_Page page,
										  HPDF_Dict* new_stream);

typedef HPDF_STATUS
(__stdcall* HPDF_Page_Insert_Shared_Content_Stream)(HPDF_Page page,
													HPDF_Dict shared_stream);


/*--- Marked content -----------------------------------------------------*/

/* BMC --not implemented yet */
/* BDC --not implemented yet */
/* EMC --not implemented yet */
/* MP --not implemented yet */
/* DP --not implemented yet */

/*--- Compatibility ------------------------------------------------------*/

/* BX --not implemented yet */
/* EX --not implemented yet */

typedef HPDF_STATUS
(__stdcall* HPDF_Page_DrawImage)(HPDF_Page    page,
								HPDF_Image   image,
								HPDF_REAL    x,
								HPDF_REAL    y,
								HPDF_REAL    width,
								HPDF_REAL    height);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_Circle)(HPDF_Page     page,
							  HPDF_REAL     x,
							  HPDF_REAL     y,
							  HPDF_REAL     ray);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_Ellipse)(HPDF_Page   page,
							   HPDF_REAL   x,
							   HPDF_REAL   y,
							   HPDF_REAL  xray,
							   HPDF_REAL  yray);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_Arc)(HPDF_Page    page,
						   HPDF_REAL    x,
						   HPDF_REAL    y,
						   HPDF_REAL    ray,
						   HPDF_REAL    ang1,
						   HPDF_REAL    ang2);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_TextOut)(HPDF_Page    page,
							   HPDF_REAL    xpos,
							   HPDF_REAL    ypos,
							   const char  *text);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_TextRect)(HPDF_Page            page,
								HPDF_REAL            left,
								HPDF_REAL            top,
								HPDF_REAL            right,
								HPDF_REAL            bottom,
								const char          *text,
								HPDF_UINT			  StringsAmmount,
								HPDF_UINT		      align,
								HPDF_UINT           *len);


typedef HPDF_STATUS
(__stdcall* HPDF_Page_SetSlideShow)(HPDF_Page              page,
									HPDF_TransitionStyle   type,
									HPDF_REAL              disp_time,
									HPDF_REAL              trans_time);


typedef HPDF_OutputIntent
(__stdcall* HPDF_ICC_LoadIccFromMem)(HPDF_Doc   pdf,
									 HPDF_MMgr   mmgr,
									 HPDF_Stream iccdata,
									 HPDF_Xref   xref,
									 int         numcomponent);

typedef HPDF_OutputIntent
(__stdcall* HPDF_LoadIccProfileFromFile)(HPDF_Doc  pdf,
										const char* icc_file_name,
										int  numcomponent);

#endif /* _HPDF_H */

// ?????? ? ?????? ?????? ??????
struct CellInfo
{
	float fWidth;
	float fHeight;
};

class HaruClass
{
protected:
	HINSTANCE m_hDllHandle;

	HPDF_Doc m_Pdf;							// ??????? ????????	
	HPDF_Page m_CurPage;					// ??????? ????????
	HPDF_Font m_CurFont;					// ??????? ?????
	HPDF_REAL m_CurTextHeight;				// ??????? ?????? ??????
	HPDF_REAL m_CurTextLeading;				// ??????? ??????????? ????????
	HPDF_Point m_CurTextPoint;				// ??????? ????? ?????? ?????? ? ????????
	_HPDF_PageSizes m_PageSize;				// ??????? ?????? ????????
	_HPDF_PageDirection m_PageDirection;	// ??????? ?????????? ????????

	// ??????? ???? ????????, ??
	float m_nTopField;
	float m_nBottomField;
	float m_nLeftField;
	float m_nRightField;

	int m_nOneStrChar;			// ?????????? ???????? ?? ?????? ?? ????? ????????
	int m_nNumberOfPages;		// ?????????? ??????? ? ?????????
	BOOL m_bNumPages;			// ????, ????? ?? ????????? ??????? ? ?????????
	char m_sFooterText[256];	// ??????? ? ????? ?????? ???? ?????? ????????

	// ?????? ???????? ??????, ??????? ????? ???????????? ?? ???? ?????? ?????????? ??????????
	char* AddSimpleText(char* sString, HPDF_UINT TextAlign);
	// ???????? ? ????? ?????? ??????? ?????? ?????? ????????
	const int MultiString(const char* sStirng, char* sBuffer);
	// ???????? ??????? ?? ???? ?? ???????? ?? ??????, ???? ???, ?? ??????? ????? ????????
	int CheckNewPageText(char* sBuffer, const int nStrings, HPDF_UINT TextAlign);
	// ???????? ????? ????????
	int AddFooter();
	// ?????? AddString ??? ????????? ?????? ? ?????? ???????
	int AddStringToTableCell(HPDF_REAL fLeft, HPDF_REAL fTop, HPDF_REAL fRight, HPDF_REAL fBottom, char* sText, HPDF_UINT TextAlign);			
	// ??????? ?????????? ?????, ?? ??????? ????? ???????? ?????. ????????? ??? ???????????? ????????????? ????????????																										
	int TextStringCount(char* sString, float nWidth);		
	// ????????????? ?????? ?????? ? ??????????? ?? ???????????
	int CorrectTableCells(float nWidth, float nHeight, int nStrings, int nColumns, char** sTableText, CellInfo* CellsInfo);	
	// ?????????? ?????? ?? ????????? ???????????? chDelimitior
	int StringSplit(const CStringA &sStr, CStringArray &sArr, char chDelimitior);
	// ????? ?????? ? ???????????? ??????? ? ???????? ?? ? csMaxStr ??????? nMaxLength
	void FindMaxString(const CStringArray &sArr, char* csMaxStr, int nMaxLength);

public:
	HaruClass();
	~HaruClass();

	// ????????????? ??????????
	int InitDll(const char* sLibName);
	// ????????????? ?????????
	int InitPdf(_HPDF_PageSizes PageSize, _HPDF_PageDirection PageDirection);
	// ????????????? ???????
	int InitFont(char* sTTFFileName, float nFontSize, float nTextLeading, int nTopField, int nBottomField, int nLeftField, int nRightField);
	// ??????? ??????? ? ?????? ???? ??????? ? ?????????
	void SetFooter(BOOL bNumPages, char* sFooterText = nullptr);
	// ???????? ?????? ??????? ????????
	float GetPageWidth(BOOL bWithFields);
	// ???????? ?????? ??????? ????????
	float GetPageHeight(BOOL bWithFields);
	// ???????? ????? ???????? ? ????? ?????????, ????????? ? pCurPage
	int InitPage();
	// ???????? ?????
	int AddString(char* sString, HPDF_UINT TextAlign = HPDF_TALIGN_LEFT);
	// ???????? ????? CString
	int AddString(CStringA sCString, HPDF_UINT TextAlign = HPDF_TALIGN_LEFT);

	// ?????????? ? ????????? ??????? ???????????? ????????? ????????
	int CreateTable(float nXpos, float nYpos, float nWidth, float nHeight, int nStrings, int nColumns, char** sTableText, HPDF_UINT TextAlign);
	// ?????????? ? ????????? ??????? ??????????? ????????? ????????
	int CreateTable(float nXpos, float nYpos, float nWidth, float nHeight, int nStrings, int nColumns, char* sTextArr, int nStringLenght, HPDF_UINT TextAlign);
	// ?????????? ? ????????? ??????? ???????? CStringArray
	int CreateTable(float nXpos, float nYpos, float nWidth, float nHeight, int nStrings, int nColumns, CStringArray &sTextArr, HPDF_UINT TextAlign);

	// ?????? ????????? ???????, ?????? ??? ????????? ? ?????, ????? ???????
	int SetPermission(const char* sOwnerPass, const char* sUserPass = nullptr, int nPermissions = HPDF_ENABLE_READ | HPDF_ENABLE_PRINT);
	// ????????? ????????
	int SavePdf(char* sPdfFileName);

private:
	HPDF_New PDF_New;
	HPDF_GetVersion PDF_GetVersion;
	HPDF_LoadTTFontFromFile PDF_LoadTTFontFromFile;
	HPDF_GetFont PDF_GetFont;
	HPDF_AddPage PDF_AddPage;

	HPDF_Page_SetSize PDF_Page_SetSize;
	HPDF_Page_SetFontAndSize PDF_Page_SetFontAndSize;
	HPDF_Page_BeginText PDF_Page_BeginText;
	HPDF_Page_EndText PDF_Page_EndText;
	HPDF_Page_TextRect PDF_Page_TextRect;
	HPDF_SaveToFile PDF_SaveToFile;

	HPDF_Page_GetHeight PDF_Page_GetHeight;
	HPDF_Page_GetWidth PDF_Page_GetWidth;

	HPDF_Page_SetTextLeading PDF_Page_SetTextLeading;
	HPDF_Page_GetCurrentTextPos PDF_Page_GetCurrentTextPos;

	HPDF_Page_MoveTo PDF_Page_MoveTo;
	HPDF_Page_LineTo PDF_Page_LineTo;
	HPDF_Page_Stroke PDF_Page_Stroke;
	HPDF_Page_Rectangle PDF_Page_Rectangle;

	HPDF_Font_MeasureText PDF_Font_MeasureText;
	HPDF_Page_GetCharSpace PDF_Page_GetCharSpace;
	HPDF_Page_GetWordSpace PDF_Page_GetWordSpace;
	HPDF_Page_TextWidth   PDF_Page_TextWidth;

	HPDF_SetPassword PDF_SetPassword;
	HPDF_SetPermission PDF_SetPermission;
	HPDF_SetEncryptionMode PDF_SetEncryptionMode;

	HPDF_Free PDF_Free;
};

