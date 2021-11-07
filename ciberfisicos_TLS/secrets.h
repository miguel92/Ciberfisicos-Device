#define SECRET

  //const char ssid[] = "JAZZTEL_vqFj";
  //const char pass[] = "72ru2ut6kvrq";

  const char ssid[] = "Wifi195X";
  const char pass[]  = "FtFfe4z0pn96HuNMaonk";
  // Configuracion de IP estatica
  // Set your Static IP address
  IPAddress local_IP(192, 168, 1, 102);
  // Set your Gateway IP address
  IPAddress gateway(192, 168, 1, 1);
  
  IPAddress subnet(255, 255, 0, 0);
  IPAddress primaryDNS(8, 8, 8, 8);   //optional
  IPAddress secondaryDNS(8, 8, 4, 4); //optional
  
  #define HOSTNAME "192.168.1.101"

  const char *MQTT_HOST = "192.168.1.101";
  const int MQTT_PORT = 8883;
  const char *MQTT_USER = "ciberfisicos1234"; // leave blank if no credentials used
  const char *MQTT_PASS = "ciberfisicos1234"; // leave blank if no credentials used

const char* local_root_ca =
  "-----BEGIN CERTIFICATE-----\n" \
  "MIIEDzCCAvegAwIBAgIUUTfrh8yvPfmakitn7AuvFphE2VkwDQYJKoZIhvcNAQEL\n" \
  "BQAwgZYxCzAJBgNVBAYTAkVTMQ8wDQYDVQQIDAZNYWxhZ2ExDzANBgNVBAcMBk1h\n" \
  "bGFnYTEMMAoGA1UECgwDVU1BMRYwFAYDVQQLDA0xOTIuMTY4LjEuMTAxMRYwFAYD\n" \
  "VQQDDA0xOTIuMTY4LjEuMTAxMScwJQYJKoZIhvcNAQkBFhhtaWd1ZWw5Mm1hcnRp\n" \
  "bkBnbWFpbC5jb20wHhcNMjExMTA2MTI0MTM1WhcNMjIxMTA2MTI0MTM1WjCBljEL\n" \
  "MAkGA1UEBhMCRVMxDzANBgNVBAgMBk1hbGFnYTEPMA0GA1UEBwwGTWFsYWdhMQww\n" \
  "CgYDVQQKDANVTUExFjAUBgNVBAsMDTE5Mi4xNjguMS4xMDExFjAUBgNVBAMMDTE5\n" \
  "Mi4xNjguMS4xMDExJzAlBgkqhkiG9w0BCQEWGG1pZ3VlbDkybWFydGluQGdtYWls\n" \
  "LmNvbTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJzAzSLkf4111v6l\n" \
  "HtW+81kIUcVjsmUBQSObb9e57jAxESDLtzxL8Tn0gSn4boTQzrEXI6YjTYVgYnKh\n" \
  "0rsXYJZD/hhAh9EPFOvVxtvYl4cT9dcQ9anEuLbAISLFT4jTwX+4ZaAP2GNQ1Pb8\n" \
  "pP7BZJGv1rAiMYgUXsfv0A0HzBgMEY63IORaP/pEk76kUjLnZROuBYHClH0z7gHJ\n" \
  "9yCd28lQ3QcH+bqar/oWZWpi52Ym/NJtR60PwpXEjYD6V/5yhfpaaCDYqy8hf/Jz\n" \
  "ntGIfb4ds+pBKe4prW04+8lDred9xJJMsZzLNuAPEihb0CstI0Bhyk3gkd18nILU\n" \
  "s6kykoECAwEAAaNTMFEwHQYDVR0OBBYEFAADGa7IeKj8WaXxaFWhMVgyJOFxMB8G\n" \
  "A1UdIwQYMBaAFAADGa7IeKj8WaXxaFWhMVgyJOFxMA8GA1UdEwEB/wQFMAMBAf8w\n" \
  "DQYJKoZIhvcNAQELBQADggEBAAYton0r8C29/34aENt8dnXEYoMVV94nGI1sSYFT\n" \
  "fQW0fCn7bhgMDVjlTL50xbUps7gXM5IaWzJ7eowuf4OdQMbv/25p4A6km79xxuBE\n" \
  "/a5JPWqBunZbaWN5vSnevJxsXiUgeeWETGRZAOcMccxmGpWQzSNJnZonBKmauZJm\n" \
  "up7Uhkub+3TON6ERyTS+DkIJsXdkD3l92VZWEGb3ruhmzCp7lhkg2prL801CdCfG\n" \
  "DBv4Wj6+TsYD9XxeaooFOwfBoTgDlZHFqUa1SUKRRvgXA8Ltycfyx2lInl581Tgt\n" \
  "PTkS200yL8vNGFnLvdo/3BLX6SZBAcS0MkytDcNs5EDJBdU=\n" \
  "-----END CERTIFICATE-----\n";
