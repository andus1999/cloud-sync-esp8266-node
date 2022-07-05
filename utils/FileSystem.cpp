#include "FileSystem.h"

FileSystem &FileSystem::getInstance()
{
  static FileSystem instance;
  return instance;
}

FileSystem::FileSystem()
{
  LittleFS.begin();
  // setInit("false");
  // setSsid("");
  // setPass("");
  // setNetworkUid("");
  // setRefreshToken("");

  //   std::string serverCert = R"EOF(
  // -----BEGIN CERTIFICATE-----
  // MIIC3zCCAkigAwIBAgIUKm+hRC17fAJuIIjWUUBc/KuyFxYwDQYJKoZIhvcNAQEL
  // BQAwcjELMAkGA1UEBhMCQVQxDDAKBgNVBAgMA09PRTENMAsGA1UEBwwEV2VsczEX
  // MBUGA1UECgwOQ2xvdWRTeW5jIFtBVF0xEjAQBgNVBAsMCUNsb3VkU3luYzEZMBcG
  // A1UEAwwQY2xvdWQtc3luYy5sb2NhbDAgFw0yMjAxMjgwNjM2MDVaGA8zMDIxMDUz
  // MTA2MzYwNVowcjELMAkGA1UEBhMCQVQxDDAKBgNVBAgMA09PRTENMAsGA1UEBwwE
  // V2VsczEXMBUGA1UECgwOQ2xvdWRTeW5jIFtBVF0xEjAQBgNVBAsMCUNsb3VkU3lu
  // YzEZMBcGA1UEAwwQY2xvdWQtc3luYy5sb2NhbDCBnzANBgkqhkiG9w0BAQEFAAOB
  // jQAwgYkCgYEAxt6K5Ve0LLYGwkfWy/BlmqNJ7ss4875g7v+QnFks6wM46QvdjM1X
  // nLHXyRT4eIicJIXAZxolybkXN+QBhszRxYplwGZlDtS5NOQa2VgTiXMInZPh8TyT
  // xCG1szkWXm+VvM9Oe46wSToHQaZP8ev2qKB76ErYvFjxVkO45ncCn50CAwEAAaNw
  // MG4wHQYDVR0OBBYEFBZBrjfpyzRYWUU8Z+gkJyxbiMTFMB8GA1UdIwQYMBaAFBZB
  // rjfpyzRYWUU8Z+gkJyxbiMTFMA8GA1UdEwEB/wQFMAMBAf8wGwYDVR0RBBQwEoIQ
  // Y2xvdWQtc3luYy5sb2NhbDANBgkqhkiG9w0BAQsFAAOBgQAJAGpIMO3YbLFhKWbz
  // ivsP6jE57B+zzloAvBGaPmF/sTLx/tUrL+EwKmrhWchXnPpqE3p2nU1A1Y3Ydjyp
  // QvcNkpCTeJM1/YfOazf+ZwLaodbbmiSqBDhC3fu9fxod6I34zWq1hFChCeNrqz7o
  // 0vcPnNHTBRgILMceee9KazmrfA==
  // -----END CERTIFICATE-----
  // )EOF";

  //   std::string serverKey = R"EOF(
  // -----BEGIN PRIVATE KEY-----
  // MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAMbeiuVXtCy2BsJH
  // 1svwZZqjSe7LOPO+YO7/kJxZLOsDOOkL3YzNV5yx18kU+HiInCSFwGcaJcm5Fzfk
  // AYbM0cWKZcBmZQ7UuTTkGtlYE4lzCJ2T4fE8k8QhtbM5Fl5vlbzPTnuOsEk6B0Gm
  // T/Hr9qige+hK2LxY8VZDuOZ3Ap+dAgMBAAECgYEAjFjD90Tk/+TackPWwAiA/Bge
  // 9ipvn/0MVb8ApIZ+n8CfakCYc2T7XrdXzS5CiHYIk/HcriaS4oEAdM4xkZt8skhw
  // 1RceCjIcC5bEcINJM/K/VdPpfcmZj/y/GiPAjGinwZmeUwAtlIDyBlsS9Yw653bS
  // VDktiF96Z9kL2YlVWiECQQDwg5Ua3We1ByGy2Qxc5HrTEIETBKgp53s/Rlca84Fz
  // KsvJ6mzDmYci5BiCkdA5+rBJhj204CZdqrygRK++/QBZAkEA06yGvq38kpLSBjBd
  // JdDqke+0vLDL8T1Tl9KPG2ooq7G0ixyY6Uu5eC4KdsnQBmmyqpseaKP/KGjWhAAJ
  // PJHQ5QJAc5KHH7Wsk+ytYMezjR+tdabEn2Lpe9lj++/NA4JnffPeoVQol4U6zqVU
  // sclnibTQ6UO8eyIKzY+xvEHFQb1JYQJBAKSH/TCn0qQnxWKUI0Mqsbn/5a+piMya
  // C6j+PMhlavmSJrDe6KimeKLGvtF4qt7hN8RO0IMrvkCtxNhTotpWyVUCQFTzDwJZ
  // kdeUzJUqC/yHjWzu3KsOYyBEEI6W80BLu77WLcPpvxfuldDsYjho+QfEqqPVYdbE
  // dmkM4UVYLwWHViI=
  // -----END PRIVATE KEY-----
  // )EOF";

  //   setServerCert(serverCert);
  //   setServerKey(serverKey);
}

FileSystem::~FileSystem()
{
  LittleFS.end();
}

std::string FileSystem::readFile(std::string filename)
{
  File f = LittleFS.open(filename.c_str(), "r");
  if (!f)
  {
    f.close();
    return "";
  }
  std::string result = f.readString().c_str();
  f.close();
  return result;
}

void FileSystem::writeFile(std::string filename, std::string content)
{
  File f = LittleFS.open(filename.c_str(), "w");
  f.write(content.c_str());
  f.close();
}

std::string FileSystem::getSsid()
{
  return readFile(SSID_FILE);
}

std::string FileSystem::getPass()
{
  return readFile(PASS_FILE);
}

std::string FileSystem::getNetworkUid()
{
  return readFile(NETWORK_UID_FILE);
}

std::string FileSystem::getRefreshToken()
{
  return readFile(REFRESH_TOKEN_FILE);
}

std::string FileSystem::getIndex()
{
  return readFile(INDEX_FILE);
}

std::string FileSystem::getSuccess()
{
  return readFile(SUCCESS_FILE);
}

std::string FileSystem::getServerCert()
{
  return readFile(SERVER_CERT_FILE);
}

std::string FileSystem::getServerKey()
{
  return readFile(SERVER_KEY_FILE);
}

std::string FileSystem::getInit()
{
  return readFile(INIT_FILE);
}

std::string FileSystem::getHtml()
{
  std::string html = R"EOF(<!DOCTYPE html>
<html>


<head>
  <meta charset="UTF-8">
  <style>
    html {
      font-family: sans-serif;
      font-size: min(7vw, 2vh);
      text-align: center;
    }

    .layout {
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      gap: 40px;
      margin: 5%;
    }

    .footer {
      line-height: 200px;
      font-size: 2rem;
      color: white;
      margin: 0;
      box-shadow: 0 50vh 0 50vh #e91e63;
      z-index: 100;
      background-color: #e91e63;
      font-weight: 700;
    }

    .title {
      font-size: 2.5rem;
      font-family: sans-serif;
    }

    .text {
      color: gray;
    }

    .info {
      padding: 20px;
      color: rgb(1, 67, 97);
      background-color: rgb(229, 246, 253);
      border-radius: 4px;
    }

    .error {
      padding: 20px;
      color: rgb(95, 33, 32);
      background-color: rgb(253, 237, 237);
      border-radius: 4px;
    }

    .success {
      padding: 20px;
      color: #66bb6a;
    }

    .pure-material-progress-circular {
      -webkit-appearance: none;
      -moz-appearance: none;
      appearance: none;
      box-sizing: border-box;
      border: none;
      border-radius: 50%;
      padding: 0.25em;
      width: 3em;
      height: 3em;
      color: #e91e63;
      background-color: transparent;
      font-size: 1em;
      overflow: hidden;
    }

    .pure-material-progress-circular::-webkit-progress-bar {
      background-color: transparent;
    }

    /* Indeterminate */
    .pure-material-progress-circular:indeterminate {
      -webkit-mask-image: linear-gradient(transparent 50%, black 50%), linear-gradient(to right, transparent 50%, black 50%);
      mask-image: linear-gradient(transparent 50%, black 50%), linear-gradient(to right, transparent 50%, black 50%);
      animation: pure-material-progress-circular 6s infinite cubic-bezier(0.3, 0.6, 1, 1);
    }

    :-ms-lang(x),
    .pure-material-progress-circular:indeterminate {
      animation: none;
    }

    .pure-material-progress-circular:indeterminate::before,
    .pure-material-progress-circular:indeterminate::-webkit-progress-value {
      content: "";
      display: block;
      box-sizing: border-box;
      margin-bottom: 0.25em;
      border: solid 0.25em transparent;
      border-top-color: currentColor;
      border-radius: 50%;
      width: 100% !important;
      height: 100%;
      background-color: transparent;
      animation: pure-material-progress-circular-pseudo 0.75s infinite linear alternate;
    }

    .pure-material-progress-circular:indeterminate::-moz-progress-bar {
      box-sizing: border-box;
      border: solid 0.25em transparent;
      border-top-color: currentColor;
      border-radius: 50%;
      width: 100%;
      height: 100%;
      background-color: transparent;
      animation: pure-material-progress-circular-pseudo 0.75s infinite linear alternate;
    }

    .pure-material-progress-circular:indeterminate::-ms-fill {
      animation-name: -ms-ring;
    }

    @keyframes pure-material-progress-circular {
      0% {
        transform: rotate(0deg);
      }

      12.5% {
        transform: rotate(180deg);
        animation-timing-function: linear;
      }

      25% {
        transform: rotate(630deg);
      }

      37.5% {
        transform: rotate(810deg);
        animation-timing-function: linear;
      }

      50% {
        transform: rotate(1260deg);
      }

      62.5% {
        transform: rotate(1440deg);
        animation-timing-function: linear;
      }

      75% {
        transform: rotate(1890deg);
      }

      87.5% {
        transform: rotate(2070deg);
        animation-timing-function: linear;
      }

      100% {
        transform: rotate(2520deg);
      }
    }

    @keyframes pure-material-progress-circular-pseudo {
      0% {
        transform: rotate(-30deg);
      }

      29.4% {
        border-left-color: transparent;
      }

      29.41% {
        border-left-color: currentColor;
      }

      64.7% {
        border-bottom-color: transparent;
      }

      64.71% {
        border-bottom-color: currentColor;
      }

      100% {
        border-left-color: currentColor;
        border-bottom-color: currentColor;
        transform: rotate(225deg);
      }
    }
  </style>
  <title>Cloud Sync</title>
</head>

<body>
  <div class="layout">
    <h1 class="title">Setup</h1>
    <p class="info">Your device is being initialized.</p>
    <progress class="pure-material-progress-circular"></progress>
    <p class="info" id='info'>Please do not close this tab. 📙</p>
  </div>
  <div class='footer'>
    Cloud Sync
  </div>

</body>

<script>
  async function setup() {
    let running = true;
    const errorTimeout = setTimeout(() => {
      running = false;
      info.className = "error";
      info.innerText = "An error occured 😥";
    }, 30000);

    const params = new URLSearchParams(window.location.search);
    const body = `${params.get('0')},${params.get('1')},${params.get('2')},${params.get('3')}`;
    console.log(body);

    while (running) {
      try {
        res = await fetch('/initialize', {
          method: 'PUT',
          body,
          signal: timeout(),
        });

        if (res.status == 200) {
          info.className = "info";
          info.innerText = "Connecting... Please wait. 🥱"
          break;
        }

      } catch (e) {
        console.log(e);
      }

      await new Promise(r => setTimeout(r, 1000));
    }

    while (running) {

      try {
        res = await fetch('/success', {
          signal: timeout()
        })

        if (res.status == 200) {
          const text = await res.text();
          console.log(text);
          clearTimeout(errorTimeout);

          if (text == "true") {
            info.className = "success";
            info.innerText = "Successfully connected to the network! 🎉"
            setTimeout(() => {
              close();
            }, 2000)
          }

          else {
            info.className = "error";
            info.innerText = "Could not connect to the network. 😥"
          }
          break;
        }
      } catch (e) {
        console.log(e);
      }

      await new Promise(r => setTimeout(r, 1000));
    }
  }

  const timeout = () => {
    let controller = new AbortController();
    setTimeout(() => controller.abort(), 1000);
    return controller.signal;
  };

  const info = document.getElementById('info');
  setup();

</script>

</html>)EOF";
  return html;
}

void FileSystem::setSsid(std::string ssid)
{
  writeFile(SSID_FILE, ssid);
}

void FileSystem::setPass(std::string pass)
{
  writeFile(PASS_FILE, pass);
}

void FileSystem::setNetworkUid(std::string networkUid)
{
  writeFile(NETWORK_UID_FILE, networkUid);
}

void FileSystem::setRefreshToken(std::string refreshToken)
{
  writeFile(REFRESH_TOKEN_FILE, refreshToken);
}

void FileSystem::setIndex(std::string html)
{
  writeFile(INDEX_FILE, html);
}

void FileSystem::setSuccess(std::string success)
{
  writeFile(SUCCESS_FILE, success);
}

void FileSystem::setServerCert(std::string cert)
{
  writeFile(SERVER_CERT_FILE, cert);
}

void FileSystem::setServerKey(std::string key)
{
  writeFile(SERVER_KEY_FILE, key);
}

void FileSystem::setInit(std::string init)
{
  writeFile(INIT_FILE, init);
}