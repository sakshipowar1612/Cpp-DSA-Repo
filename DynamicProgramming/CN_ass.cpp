#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> splitAddress(string str, char delimeter)
{
    int i = 0;
    vector<int> ans;
    while (i < str.length())
    {
        int sum = 0;
        while (str[i] != delimeter && i < str.length())
        {
            sum = sum * 10 + str[i] - '0';
            i++;
        }
        ans.push_back(sum);
        i++;
    }
    return ans;
}

void validate_ip(vector<int> ip_address)
{
    if (ip_address.size() != 4)
    {
        throw invalid_argument("Invalid IP address format");
    }
    for (int octet : ip_address)
    {
        if (octet < 0 || octet > 255)
        {
            throw invalid_argument("IP address octets must be between 0 and 255");
        }
    }
}

vector<int> calculate_network_address(const vector<int> &ip, const vector<int> &subnet)
{
    vector<int> network_address;
    for (size_t i = 0; i < ip.size(); ++i)
    {
        network_address.push_back(ip[i] & subnet[i]);
    }
    return network_address;
}

void printAddress(vector<int> vec)
{
    for (int i : vec)
    {
        cout << i << ".";
    }
    cout << endl;
}

vector<int> calculate_broadcast_address(const std::vector<int>& network, const vector<int>& subnet) {
    vector<int> broadcast_address;
    for (size_t i = 0; i < network.size(); ++i) {
        broadcast_address.push_back(network[i] | (~subnet[i] & 0xFF));
    }
    return broadcast_address;
}

int main()
{
    string ip_address;
    string subnet_mask;

    cout << "Enter ip address(Type C) : ";
    cin >> ip_address;
    cout << "ip address : " << ip_address << endl;
    cout << "Enter subnet mask : ";
    cin >> subnet_mask;
    cout << "subnet mask : " << subnet_mask << endl;

    vector<int> ipAddress = splitAddress(ip_address, '.');
    cout << "ip address : " << endl;
    printAddress(ipAddress);
    vector<int> subnetMask = splitAddress(subnet_mask, '.');
    cout << "Subnet Mask : " << endl;
    printAddress(subnetMask);
    cout << "Network address : " << endl;
    printAddress(calculate_network_address(ipAddress, subnetMask));

}