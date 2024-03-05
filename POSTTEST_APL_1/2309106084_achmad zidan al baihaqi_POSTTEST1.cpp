#include <iostream>
#include <string>
#include <iomanip>

void menu() {
    std::cout << R"(
    === MENU ===
    1. Login
    2. Keluar
    )" << std::endl;
}

void menu_konversi() {
    std::cout << R"(
    1. Konversi Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)
    2. Konversi Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)
    3. Konversi Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)
    4. Konversi Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)
    )" << std::endl;
}

int main() {
    while (true) {
        menu();
        std::string pilih;
        std::cout << "masukan pilihan anda: ";
        std::cin >> pilih;

        if (pilih == "1") {
            std::cout << "masuk" << std::endl;
            std::string nama, nim;
            int percobaan = 0;
            std::string pass_;

            std::cout << "masukan nama anda: ";
            std::cin >> nama;
            std::cout << "masukan nim anda: ";
            std::cin >> nim;
            pass_ = nim.substr(nim.length() - 3, 3);
            std::string passs;

            while (percobaan < 3) {
                std::cout << "masukan password anda (password menggunakan 3 nomor akhir NIM): ";
                std::cin >> passs;
                if (passs == pass_) {
                    menu_konversi();
                    std::string pilih2;
                    std::cout << "masukan pilihan anda: ";
                    std::cin >> pilih2;
                    if (pilih2 == "1") {
                        try {
                            double kmpj;
                            std::cout << "masukan kecepatan dalam kilometer/jam: ";
                            std::cin >> kmpj;
                            double cmpj = kmpj * 100000 / 3600;
                            double mtrpd = kmpj * 1000 / 3600;
                            double milpj = kmpj / 1.60934;
                            std::cout << "Hasil konversi:" << cmpj << " cm/detik" << std::endl;
                            std::cout << "hasil konversi:" << mtrpd << " m/detik" << std::endl;
                            std::cout << "hasil konversi :" << milpj << " mil/jam" << std::endl;
                        }
                        catch (...) {
                            std::cout << "Masukkan harus berupa angka." << std::endl;
                        }
                    }
                    // Tambahkan kasus lainnya untuk konversi di sini
                    else {
                        std::cout << "pilihan anda tidak benar" << std::endl;
                    }
                }
                else {
                    percobaan += 1;
                    std::cout << "salah" << std::endl;
                }
            }
        }
        else if (pilih == "2") {
            std::cout << "keluar" << std::endl;
            break;
        }
        else {
            std::cout << "pilihan tidak tersedia" << std::endl;
        }
    }

    return 0;
}
