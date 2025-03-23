
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

// 1. KONFIGURASI WIFI
const char* ssid = "GANTI";      // Ganti dengan SSID Anda
const char* password = "GANTI";   // Ganti dengan password WiFi

// 2. KAMUS LENGKAP (Semua 500+ kosakata)
const char dictionary_json[] PROGMEM = R"rawliteral(

{
  "apa": "inu",
  "kemana": "kenpi",
  "dimana": "kenpi",
  "siapa": "ahe",
  "kapan": "mi'an",
  "bagaimana": "kumpin",
  "putih": "putek",
  "hitam": "saleng",
  "merah": "bala",
  "1": "ca'",
  "2": "dua",
  "3": "telu",
  "4": "pat",
  "5": "lema",
  "6": "nem",
  "7": "tujuk",
  "8": "aya",
  "9": "pe'en",
  "10": "puluk",
  "11": "ca' elas",
  "12": "dua elas",
  "13": "telu elas",
  "14": "pat elas",
  "15": "lema elas",
  "16": "nem elas",
  "17": "tujuk elas",
  "18": "aya elas",
  "19": "pe'en elas",
  "20": "dua puluk",
  "30": "telu puluk",
  "40": "pat puluk",
  "50": "lema puluk",
  "60": "nem puluk",
  "70": "tujuk puluk",
  "80": "aya puluk",
  "90": "pe'en puluk",
  "100": "ca' ato",
  "1000": "ca' ibu",
  "1000000": "ca' juta",
  "satu": "ca'",
  "dua": "dua",
  "tiga": "telu",
  "empat": "pat",
  "lima": "lema",
  "enam": "nem",
  "tujuh": "tujuk",
  "delapan": "aya",
  "sembilan": "pe'en",
  "sepuluh": "puluk",
  "sebelas": "ca' elas",
  "dua belas": "dua elas",
  "tiga belas": "telu elas",
  "empat belas": "pat elas",
  "lima belas": "lema elas",
  "enam belas": "nem elas",
  "tujuh belas": "tujuk elas",
  "delapan belas": "aya elas",
  "sembilan belas": "pe'en elas",
  "dua puluh": "dua puluk",
  "tiga puluh": "telu puluk",
  "empat puluh": "pat puluk",
  "lima puluh": "lema puluk",
  "enam puluh": "nem puluk",
  "tujuh puluh": "tujuk puluk",
  "delapan puluh": "aya puluk",
  "sembilan puluh": "pe'en puluk",
  "seratus": "ca' ato",
  "seribu": "ca' ibu",
  "sejuta": "ca' juta",
  "ratus": "ato",
  "ribu": "ibu",
  "belas": "elas",
  "nya": "la",
  "aku": "ake",
  "ada": "aun",
  "anjing": "udut",
  "ayam": "yap",
  "babi": "babui",
  "banteng": "kalasiau",
  "bebek": "bidik",
  "belalang": "kade",
  "beruang": "buang",
  "biawak": "kabuk",
  "buaya": "baya",
  "burung": "sui",
  "cicak": "aru",
  "gajah": "kesun",
  "harimau": "lenjau",
  "ikan": "atuk",
  "lele": "kati",
  "patin": "selareng",
  "kambing": "kadeng",
  "kancil": "pelanuk",
  "kecoa": "lepa",
  "kepiting": "yu",
  "kijang": "payak",
  "kodok": "sui",
  "kucing": "sing",
  "kupu-kupu": "bamper",
  "lalat": "langau",
  "cacing": "lati",
  "macan": "kule",
  "monyet": "kuyata",
  "nyamuk": "jamok",
  "rusa": "uca",
  "siput": "sik/ulung",
  "tikus": "belabau",
  "ular": "tuduk",
  "bagus": "tia",
  "baru": "mading",
  "besar": "bio",
  "cepat": "sangit",
  "kelakuan": "puyan",
  "kosong": "mpi un",
  "malas": "malat",
  "nyata": "lan",
  "pelit": "ma'em",
  "ringan": "nyian",
  "sehat": "agat",
  "pagi": "tading nempam",
  "siang": "naktau",
  "malam": "nataup",
  "sibuk": "lamak",
  "berbagai": "kado",
  "atau": "ataw",
  "dan": "ngan",
  "dari": "cen",
  "berasal": "cen",
  "diantara": "dalau",
  "juga": "pe",
  "karena": "uban",
  "ke": "koq",
  "mending": "lepa ini",
  "saat": "sa taup",
  "sebelum": "ken'a",
  "tapi": "untepu'o",
  "tetapi": "untepu'o",
  "setelah": "lepa kadi",
  "supaya": "apan",
  "agar": "apan",
  "untuk": "un",
  "yang": "yak",
  "adalah": "ja ne",
  "ialah": "ialah",
  "kalau": "awa'",
  "badan": "usa",
  "baju": "sapai",
  "buah": "buaq",
  "keledang": "ta'ep",
  "cempedak": "nakan",
  "lay": "pakit",
  "rambutan": "sangit",
  "desa": "lepo",
  "gula": "gula'k",
  "jendela": "sekan",
  "kamar": "tilung lundo",
  "kursi": "adan",
  "lemari": "buan",
  "lontong": "kanen lema'k",
  "makanan": "penguman",
  "memakan": "uman",
  "dimakan": "uman",
  "meja": "mejak",
  "minuman": "nisep ia",
  "minyak": "lenya",
  "mobil": "oto",
  "goreng": "saga",
  "pasar": "pasen",
  "piring": "kiyat",
  "pondok": "lepau",
  "rumah": "amin",
  "sungai": "alo",
  "tas": "bek",
  "telur": "telo",
  "kandang": "liwang",
  "sudah": "lepa",
  "sampai": "pa",
  "balik": "liwer",
  "bangun": "taga",
  "belajar": "pekalai",
  "berangkat": "tai te",
  "bermain": "piat",
  "berpikir": "pekimet",
  "bikin": "uyan",
  "buat": "uyan",
  "bilang": "kun",
  "sampaikan": "kun",
  "bohong": "pala",
  "bolos": "tai kelap",
  "jalan": "masat",
  "jalan-jalan": "masat-masat",
  "jangan": "ain",
  "keluar": "kawang",
  "bekerja": "gayeng",
  "kerja": "gayeng",
  "kerjakan": "gayeng",
  "ketahui": "tisen",
  "tau": "tisen",
  "makan": "uman",
  "mandi": "ndu'",
  "masak": "pesak",
  "masuk": "ke dalem",
  "melihat": "ngeneng",
  "melihatnya": "ngeneng ia",
  "membeli": "meli",
  "mendengar": "ngeninga",
  "menyanyi": "ngendau",
  "minum": "nisep",
  "nyaring": "bia",
  "singgah": "ngena'k",
  "tinggal": "ngena'k",
  "disini": "ki",
  "terima": "tiga",
  "kasih": "tawai",
  "tidur": "lundog",
  "pindah": "buaw",
  "berteduh": "ngedingan",
  "petubo": "pelihara",
  "adegan": "kaa",
  "banyak": "kado",
  "sekali": "ale",
  "boleh": "kong",
  "dulu": "ading",
  "hari": "tau",
  "ingatan": "kimet",
  "kemarin": "nya'ep rei",
  "memang": "adang",
  "suka": "uba",
  "cinta": "uba",
  "sayang": "uba",
  "melewati": "lapa",
  "sama": "kuwa",
  "nama": "ngadan",
  "namaku": "ngadan keq",
  "ku": "keq",
  "oke": "aha",
  "iya": "aha",
  "pulang": "ula",
  "sangat": "ali'",
  "semua": "mung",
  "seperti": "kuaq",
  "suaranya": "isu'a",
  "tentu": "ina",
  "saja": "na",
  "tidak": "nda",
  "gayeng": "tugas",
  "sekolah": "sekula",
  "kabar": "denga",
  "berita": "denga",
  "hal": "denga",
  "kejadian": "denga",
  "salah": "bep",
  "datang": "nay",
  "tersisa": "naung",
  "bapak": "amai",
  "bersama": "ilu mung",
  "hantu": "bali",
  "ibu": "uweq",
  "kalian": "ikem",
  "kami": "ame",
  "kamu": "ikoq",
  "kau": "ikoq",
  "kita": "ilu",
  "saya": "ake",
  "teman": "tuyang",
  "mereka": "ida",
  "masing": "tengen",
  "masing-masing": "tengen-tengen",
  "senin": "keca",
  "selasa": "kedua",
  "rabu": "ketelu",
  "kamis": "tepat",
  "jumat": "kelema",
  "sabtu": "kenem",
  "minggu": "minggu",
  "adik": "ari'",
  "angin": "bayu",
  "air": "sungai",
  "rumahmu": "lamin engku",
  "ambil": "alak",
  "baik": "lemeli",
  "berenang": "nyatung",
  "bocor": "tudok",
  "berak": "lepin",
  "berdiri": "ngrejeng",
  "bicara": "petirak",
  "bintang": "betuen",
  "besok": "nembam",
  "banjir": "layap",
  "berapa": "kudak",
  "celana": "seluen",
  "cabe": "lia",
  "duduk": "adung",
  "dingin": "nyeng",
  "gelap": "mendem",
  "gigi": "jipen",
  "gemuk": "lembo",
  "gendong": "bak",
  "gunung": "mudung",
  "gundul": "ulok",
  "garam": "usen",
  "hidup": "mudip",
  "hidung": "ndung",
  "hutan": "a'ut",
  "haus": "moang laset",
  "jernih": "litut",
  "mamak": "tinam",
  "jatuh": "labok",
  "jauh": "cok",
  "jelek": "ja'at",
  "kencing": "nyengit",
  "kenyang": "beso",
  "kepala": "ulu",
  "keatas": "kempou",
  "naik": "kempou",
  "kembali": "ulek",
  "kemarau": "tagak",
  "kakek": "pui",
  "nenek": "pui",
  "kakak": "seken",
  "kaki": "taket",
  "kurus": "mae",
  "kecil": "ang",
  "lihat": "maat",
  "lapar": "lau",
  "laki": "laki",
  "lidah": "uma",
  "alkohol": "jakan",
  "mabok": "meduk",
  "madu": "layuk",
  "orang": "lakeng",
  "mencari": "mita",
  "malu": "sa'e",
  "menyelam": "lemeset",
  "memanjat": "lemaket",
  "menanam": "mula",
  "menari": "kanjet",
  "mau": "obak",
  "mata": "mata",
  "mimpi": "ngenupi",
  "mencuri": "mengelau",
  "menangis": "menange",
  "mana": "mpi",
  "mati": "matae",
  "menyeberang": "pelawat",
  "peluk": "nyekapu",
  "panen": "maju",
  "perut": "batek",
  "pahit": "pait",
  "pintu": "pamen",
  "pakaian": "sapai",
  "perahu": "alut",
  "parang": "mandau",
  "panjang": "dadok",
  "pendek": "bu'et",
  "pedas": "sanit",
  "pergi": "tei",
  "pandai": "encam",
  "pohon": "puun",
  "rindu": "menok menawai",
  "sayur": "lekey",
  "suami mu": "laki koq",
  "satu bulan": "ca bulan",
  "setuju": "aha",
  "selimut": "kelumah",
  "benar": "sio",
  "di": "ka",
  "sini": "ini",
  "sana": "ina",
  "situ": "ina",
  "berlari": "kasa",
  "berbaring": "meken",
  "bersandar": "nyendei",
  "berkebun": "uyam pula",
  "nasi": "kenan",
  "pedagang": "toke",
  "nangis": "nange",
  "main": "piat",
  "ya": "aha",
  "antara": "aang",
  "hilir": "aba",
  "peraturan": "adet",
  "kenapa": "adi",
  "mengapa": "adi",
  "kesatu": "ading",
  "dahulu": "ading",
  "terdahulu": "ading",
  "lalang": "ai'",
  "pasir": "ait",
  "tuntun": "ajak",
  "baris": "ajat",
  "keberanian": "akang",
  "memberanikan": "ngakang",
  "berani": "makang",
  "ide": "aken",
  "pikiran": "aken",
  "kebijaksanaan": "aken",
  "pinggang": "aking",
  "rakit": "akit",
  "kapal": "akit",
  "meraup": "makup",
  "cupu": "a'i'",
  "jantan": "a'ung",
  "belukar": "ma'ut",
  "semak": "ma'ut",
  "bersemak": "ma'ut",
  "berumput": "ma'ut",
  "rumput": "ma'ut",
  "dapat": "ala'",
  "mendapatkan": "ala'",
  "bisa": "ala'",
  "ranting": "alan",
  "setengah": "alang",
  "kebiasaan": "alay",
  "lazim": "alay",
  "jalur": "ale",
  "banding": "aliu",
  "arus": "alo",
  "mengukur": "alut",
  "simpan": "mambin",
  "menyimpan": "mambin",
  "memegang": "mambin",
  "pegang": "mambin",
  "memelihara": "mambim",
  "tersimpan": "pambin",
  "rantai": "ambit",
  "bodoh": "ameng",
  "bisu": "ameng",
  "keluarga": "amit",
  "mungkin": "amu'",
  "kekanakkanakan": "pekanak",
  "kembar": "pit",
  "saudara": "aung",
  "saudari": "aung",
  "menatap": "aneng",
  "tatap": "aneng",
  "kulit": "anit",
  "punya": "anun",
  "milik": "anun",
  "rintangan": "apat",
  "aral": "apat",
  "halangan": "apat",
  "terlintang": "papat",
  "tertahan": "papat",
  "terhalang": "papat",
  "menara": "apaw",
  "penara": "apaw",
  "bukit": "apaw",
  "tali": "apay",
  "cacat": "apet",
  "kapur": "apo",
  "tertarik": "arep",
  "berminat": "arep",
  "keinginan": "arep",
  "cenderung": "arep",
  "lahap": "asam",
  "rakus": "asam",
  "likut": "mundur",
  "asal": "asen",
  "jurang": "asep",
  "lembah": "asep",
  "beratus": "ato",
  "meletakkan": "maung",
  "menempatkan": "maung",
  "menaruh": "maung",
  "andai": "awa'",
  "basi": "basi",
  "basa'": "basah",
  "batu": "batu",
  "bayar": "bayan",
  "teriak": "bika'",
  "kuning": "bila'",
  "pesawat": "bilun",
  "racun": "bisa'",
  "sisir": "bit",
  "cemas": "bisaw",
  "buku": "buk",
  "bersih": "bui'",
  "bola": "bula",
  "aneh": "bulen",
  "gila": "buling",
  "bom": "bum",
  "bermusuhan": "pebunu'",
  "selamat": "bunut",
  "memar": "buok",
  "marah": "busi'",
  "botol": "butun",
  "lain": "cena'an",
  "darah": "daa'",
  "janji": "daji'",
  "tangkap": "dakep",
  "ketika": "dalaw",
  "daerah": "dalé",
  "sesat": "daru",
  "alat": "de'buat",
  "terang": "dema",
  "hemat": "demun",
  "lambat": "dena'",
  "kuat": "denggep",
  "tahu": "tisen",
  "lampu": "titiw",
  "bengkak": "tukuk",
  "lupa": "turan",
  "susu": "tusu",
  "muntah": "tuta'",
  "dermaga": "tuun",
  "hujan": "ujan",
  "tangan": "uju' ",
  "langsung": "umba",
  "dada": "usuk",
  "otak": "utek",
  "membuat": "uyan"
}
)rawliteral";

// 3. KODE HTML/CSS/JS (Dalam PROGMEM)
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dayak Kenyah Translator</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600&display=swap');
        :root {
            --primary: #6ba3be;
            --secondary: #475069;
            --background: #2d3342;
            --text-main: #ffffff;
            --text-secondary: #b0b6c3;
            --hover: #8ab4c7;
        }
        * { margin:0; padding:0; box-sizing:border-box; }
        body {
            font-family: 'Inter', sans-serif;
            background: var(--background);
            color: var(--text-main);
            line-height:1.6;
            min-height:100vh;
            display:flex;
            flex-direction:column;
        }
        .container {
            flex:1;
            padding:2rem;
            max-width:1200px;
            margin:0 auto;
        }
        .header {
            text-align:center;
            margin-bottom:2rem;
        }
        .logo {
            width:150px;
            border-radius:8px;
            margin-bottom:1rem;
        }
        .title {
            font-size:2.5rem;
            color:var(--primary);
        }
        .description {
            color:var(--text-secondary);
            font-size:0.9rem;
            margin-top:1rem;
        }
        .translator-box {
            background:var(--secondary);
            padding:2rem;
            border-radius:12px;
            box-shadow:0 4px 6px rgba(0,0,0,0.1);
        }
        .lang-indicator {
            font-weight:500;
            color:var(--text-secondary);
            margin:1rem 0;
        }
        .input-group {
            display:flex;
            gap:1rem;
            margin:1rem 0;
        }
        .text-input {
            flex:1;
            padding:1rem;
            background:var(--background);
            color:var(--text-main);
            border-radius:8px;
            min-height:100px;
            resize:vertical;
        }
        .swap-btn {
            background:var(--primary);
            color:white;
            border:none;
            padding:0.8rem 1.2rem;
            border-radius:8px;
            cursor:pointer;
            font-size:1.2rem;
        }
        .swap-btn:hover { background:var(--hover); }
        .output-box {
            background:var(--background);
            padding:1rem;
            border-radius:8px;
            min-height:100px;
            margin-top:1rem;
        }
        .social-section {
            text-align:center;
            padding:2rem;
            background:var(--secondary);
            margin-top:auto;
        }
        .social-link {
            color:var(--text-main);
            margin:0 0.5rem;
            font-size:1.2rem;
        }
        .social-link:hover { color:var(--primary); }
        .footer {
            color:var(--text-secondary);
            font-size:0.8rem;
        }
        @media (max-width:768px) {
            .input-group { flex-direction:column; }
            .swap-btn { width:100%; margin-top:0.5rem; }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <img src="https://i.pinimg.com/736x/cc/82/6d/cc826d6dccc9dcf66760320f295a688f.jpg" class="logo">
            <h1 class="title">Dayak Kenyah Translator</h1>
            <p class="description">
                Penerjemah bahasa Indonesia ↔ Dayak Kenyah dengan 500+ kosakata pertama yang menggunakan ESP 32 sebagai Webserver, Menggunakan C/C++ (bukan Python) untuk menjalankan logika terjemahan.
            </p>
        </div>

        <div class="translator-box">
            <div class="lang-indicator">
                Translate from: <span id="currentLang">Indonesian</span>
            </div>
            
            <div class="input-group">
                <textarea class="text-input" 
                          id="inputText"
                          placeholder="Enter Indonesian text..."></textarea>
                <button class="swap-btn" onclick="swapLanguage()">↔</button>
            </div>

            <div class="lang-indicator">
                Translation Result (<span id="targetLang">Dayak Kenyah</span>):
            </div>
            <div class="output-box">
                <p id="outputText"></p>
            </div>
        </div>
    </div>

    <div class="social-section">
        <div class="social-links">
            <a href="https://github.com/RyuHiiragi" class="social-link" target="_blank"><i class="fab fa-github"></i></a>
            <a href="https://www.instagram.com/kysukamieayam" class="social-link" target="_blank"><i class="fab fa-instagram"></i></a>
        </div>
        <div class="footer">
            <p>Muhammad Rizky Saputra</p>
            <p>XI TJKT 2</p>
        </div>
    </div>

    <script>
        let currentLang = 'id';

        function swapLanguage() {
            currentLang = currentLang === 'id' ? 'dyk' : 'id';
            document.getElementById('currentLang').textContent = 
                currentLang === 'id' ? 'Indonesian' : 'Dayak Kenyah';
            document.getElementById('targetLang').textContent = 
                currentLang === 'id' ? 'Dayak Kenyah' : 'Indonesian';
            document.getElementById('inputText').placeholder = 
                `Enter ${currentLang === 'id' ? 'Indonesian' : 'Dayak'} text...`;
            document.getElementById('inputText').value = '';
            document.getElementById('outputText').textContent = '';
        }

        function translateText() {
            const input = document.getElementById('inputText').value.trim().toLowerCase();
            if (!input) return;

            fetch(`/translate?text=${encodeURIComponent(input)}&lang=${currentLang}`)
                .then(response => response.text())
                .then(result => {
                    document.getElementById('outputText').textContent = result;
                });
        }

        document.getElementById('inputText').addEventListener('input', translateText);
    </script>
</body>
</html>
)rawliteral";

// 4. KONFIGURASI SERVER
WebServer server(80);
StaticJsonDocument<8192> dict; // Diperbesar untuk 500+ kosakata

// Deklarasi fungsi untuk menghindari error
void handleRoot();
void handleTranslate();

void setup() {
  Serial.begin(115200);
  
  // Sambungkan ke WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nTerhubung! IP: " + WiFi.localIP().toString());

  // Parsing kamus dari PROGMEM
  DeserializationError error = deserializeJson(dict, dictionary_json);
  if (error) {
    Serial.println("Error parsing JSON: " + String(error.c_str()));
    return;
  }

  // Routing server
  server.on("/", HTTP_GET, handleRoot);
  server.on("/translate", HTTP_GET, handleTranslate);
  server.begin();
}

void loop() {
  server.handleClient();
}

// Implementasi fungsi handleRoot
void handleRoot() {
  server.send_P(200, "text/html", index_html);
}

// Implementasi fungsi handleTranslate
void handleTranslate() {
  if (!server.hasArg("text") || !server.hasArg("lang")) {
    server.send(400, "text/plain", "Parameter tidak lengkap");
    return;
  }

  String text = server.arg("text");
  String lang = server.arg("lang");
  text.toLowerCase();

  String result = "";

  if (lang == "id") {
    // Cek apakah input utuh ada di kamus
    if (dict.containsKey(text)) {
      result = dict[text].as<const char*>();
    } else {
      // Pisah per kata
      int start = 0;
      int end = text.indexOf(' ');
      while (end != -1) {
        String word = text.substring(start, end);
        if (dict.containsKey(word)) {
          result += String(dict[word].as<const char*>()) + " ";
        } else {
          result += word + " ";
        }
        start = end + 1;
        end = text.indexOf(' ', start);
      }
      String lastWord = text.substring(start);
      result += dict.containsKey(lastWord) ? String(dict[lastWord].as<const char*>()) : lastWord;
    }
  } else {
    // Cek apakah input utuh ada di value kamus
    bool foundFull = false;
    for (JsonPair pair : dict.as<JsonObject>()) {
      if (pair.value().as<String>().equalsIgnoreCase(text)) {
        result = pair.key().c_str();
        foundFull = true;
        break;
      }
    }
    if (!foundFull) {
      // Pisah per kata untuk terjemahan Dayak -> Indonesia
      int start = 0;
      int end = text.indexOf(' ');
      while (end != -1) {
        String word = text.substring(start, end);
        bool found = false;
        for (JsonPair pair : dict.as<JsonObject>()) {
          if (pair.value().as<String>().equalsIgnoreCase(word)) {
            result += String(pair.key().c_str()) + " ";
            found = true;
            break;
          }
        }
        if (!found) result += word + " ";
        start = end + 1;
        end = text.indexOf(' ', start);
      }
      String lastWord = text.substring(start);
      bool foundLast = false;
      for (JsonPair pair : dict.as<JsonObject>()) {
        if (pair.value().as<String>().equalsIgnoreCase(lastWord)) {
          result += pair.key().c_str();
          foundLast = true;
          break;
        }
      }
      if (!foundLast) result += lastWord;
    }
  }

  server.send(200, "text/plain", result);
}
