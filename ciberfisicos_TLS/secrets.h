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
  const char *MQTT_USER = "esp32"; // leave blank if no credentials used
  const char *MQTT_PASS = ""; // leave blank if no credentials used

const char* local_root_ca =
  "-----BEGIN CERTIFICATE-----\n" \
  "MIIEDzCCAvegAwIBAgIUB0P0T1K60hPDY4Cq5yexK+CACOQwDQYJKoZIhvcNAQEL\n" \
  "BQAwgZYxCzAJBgNVBAYTAkVTMQ8wDQYDVQQIDAZNYWxhZ2ExDzANBgNVBAcMBk1h\n" \
  "bGFnYTEMMAoGA1UECgwDVU1BMRYwFAYDVQQLDA0xOTIuMTY4LjEuMTAxMRYwFAYD\n" \
  "VQQDDA0xOTIuMTY4LjEuMTAxMScwJQYJKoZIhvcNAQkBFhhtaWd1ZWw5Mm1hcnRp\n" \
  "bkBnbWFpbC5jb20wHhcNMjExMTEwMjE0ODMyWhcNMzExMTA4MjE0ODMyWjCBljEL\n" \
  "MAkGA1UEBhMCRVMxDzANBgNVBAgMBk1hbGFnYTEPMA0GA1UEBwwGTWFsYWdhMQww\n" \
  "CgYDVQQKDANVTUExFjAUBgNVBAsMDTE5Mi4xNjguMS4xMDExFjAUBgNVBAMMDTE5\n" \
  "Mi4xNjguMS4xMDExJzAlBgkqhkiG9w0BCQEWGG1pZ3VlbDkybWFydGluQGdtYWls\n" \
  "LmNvbTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMk2cndSPyhdtxhS\n" \
  "ufCKWrSCVkwg+oBNWpBuZoD+XCE+QANLvB45gojT3CVIpjHjyTLP6r6Kb2WK7npZ\n" \
  "Ct2Dw/vGFm20UXFdjNJ4ZpUKd8fk/Aq88e0P7IlfDmJK0zO4NTy4isMeYv9V7yOU\n" \
  "NXF0/d273AsL4i+07XNt51c7rbfaET9eJNnmDo0g75lc9HV4e7GE2uFBAKgibKL4\n" \
  "clR9MCnnwjGKSLYkBQIKMP0GAq8SEqYUmAoOl4hbcb02iHnabPp3ehZLaVfRR8O8\n" \
  "wARPdRg/CrNCI5zqdTjtNXauNsQXzuRI9+Nr321bifhITupy43YFyrdPJXmVRIx7\n" \
  "MTGJeVcCAwEAAaNTMFEwHQYDVR0OBBYEFP6Wp1+W0DG/69uUnhyfWP0MoiTRMB8G\n" \
  "A1UdIwQYMBaAFP6Wp1+W0DG/69uUnhyfWP0MoiTRMA8GA1UdEwEB/wQFMAMBAf8w\n" \
  "DQYJKoZIhvcNAQELBQADggEBAC6ItovmedNCKtGVmMm2b+Cb0i3x2ZYuW8Iel2Ig\n" \
  "jCkR+w8LNeMgC2vZtzzUfRN6qLFa6jOhaNR4BQZAr8oYVhPIXQJkqKLu3bxX6H8o\n" \
  "RgnAFMF3jZlSdxtOVmw9o3ScMncc9Kol3abKYOHtshY9nuDJOiw8rCEvJDAJuBTS\n" \
  "SoZM3Y/0yGFYGw29Y3C+1CvoF/g4A++XDhx/uQGhGlei6T5A7iEXXM7krUuFD8K8\n" \
  "d1JQJaFtf2eMNFpIQ/gCTR6Brp85RsUxZGXTggKi11NwmFDGONRSGyHhRn5CWR3U\n" \
  "3d7k6OEz9+I746IbCMKFJ5dcXjX60cWItobXRYws4s0RhPY=\n" \
  "-----END CERTIFICATE-----\n";
