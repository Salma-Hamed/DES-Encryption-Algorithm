#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string XOR(string s1, string s2)
{
	string s_xor = "";
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[i])
		{
			s_xor += "0";
		}
		else
		{
			s_xor += "1";
		}
	}
	return s_xor;
}
string getStringLeft(string fullKey)
{
	string left_part = "";
	for (int i = 0; i < fullKey.length() / 2; i++)
	{
		left_part += fullKey[i];
	}
	return left_part;
}
string getStringRight(string fullKey)
{
	string right_part = "";
	for (int i = fullKey.length() / 2; i < fullKey.length(); i++)
	{
		right_part += fullKey[i];
	}
	return right_part;
}
string shift_left(string key_part)
{
	string new_part = "";
	for (int i = 1; i < key_part.length(); i++)
	{
		new_part += key_part[i];
	}
	new_part += key_part[0];
	return new_part;
}
string double_shift_left(string sh)
{
	string sh1 = "", sh2 = "";
	sh1 = shift_left(sh);
	sh2 = shift_left(sh1);
	return sh2;
}
string str2b(string k1) // converting hex input into binary stored in a string
{
	string kb = "";
	for (int i = 0; i < k1.length(); i++)
	{
		switch (k1[i])
		{
		case '0':
			kb += "0000";
			break;
		case '1':
			kb += "0001";
			break;
		case '2':
			kb += "0010";
			break;
		case '3':
			kb += "0011";
			break;
		case '4':
			kb += "0100";
			break;
		case '5':
			kb += "0101";
			break;
		case '6':
			kb += "0110";
			break;
		case '7':
			kb += "0111";
			break;
		case '8':
			kb += "1000";
			break;
		case '9':
			kb += "1001";
			break;
		case 'A':
			kb += "1010";
			break;
		case 'B':
			kb += "1011";
			break;
		case 'C':
			kb += "1100";
			break;
		case 'D':
			kb += "1101";
			break;
		case 'E':
			kb += "1110";
			break;
		case 'F':
			kb += "1111";
			break;
		}
	}
	return kb;
}
string b2hex(string bstr) // converting binary number into hex stored in a string
{
	string substr = "";
	string hexstr = "";
	for (int i = 0; i < bstr.length(); i += 4)
	{
		substr = bstr.substr(i, 4);
		if (substr == "0000")hexstr += "0";
		else if (substr == "0001")hexstr += "1";
		else if (substr == "0010")hexstr += "2";
		else if (substr == "0011")hexstr += "3";
		else if (substr == "0100")hexstr += "4";
		else if (substr == "0101")hexstr += "5";
		else if (substr == "0110")hexstr += "6";
		else if (substr == "0111")hexstr += "7";
		else if (substr == "1000")hexstr += "8";
		else if (substr == "1001")hexstr += "9";
		else if (substr == "1010")hexstr += "A";
		else if (substr == "1011")hexstr += "B";
		else if (substr == "1100")hexstr += "C";
		else if (substr == "1101")hexstr += "D";
		else if (substr == "1110")hexstr += "E";
		else if (substr == "1111")hexstr += "F";
	}
	return hexstr;
}
string PC1(string p) // minimizing key into 56 bits instead of 64 bits 
{
	string kp = "", k = "";
	k = str2b(p);
	kp = k[56]; kp += k[48]; kp += k[40]; kp += k[32]; kp += k[24]; kp += k[16]; kp += k[8];
	kp += k[0]; kp += k[57]; kp += k[49]; kp += k[41]; kp += k[33]; kp += k[25]; kp += k[17];
	kp += k[9]; kp += k[1]; kp += k[58]; kp += k[50]; kp += k[42]; kp += k[34]; kp += k[26];
	kp += k[18]; kp += k[10]; kp += k[2]; kp += k[59]; kp += k[51]; kp += k[43]; kp += k[35];
	kp += k[62]; kp += k[54]; kp += k[46]; kp += k[38]; kp += k[30]; kp += k[22]; kp += k[14];
	kp += k[6]; kp += k[61]; kp += k[53]; kp += k[45]; kp += k[37]; kp += k[29]; kp += k[21];
	kp += k[13]; kp += k[5]; kp += k[60]; kp += k[52]; kp += k[44]; kp += k[36]; kp += k[28];
	kp += k[20]; kp += k[12]; kp += k[4]; kp += k[27]; kp += k[19]; kp += k[11]; kp += k[3];

	return kp;
}
string PC2(string k) // minimizing key into 48 bits instead of 56 bits 
{
	string kp = "";
	kp = k[13]; kp += k[16]; kp += k[10]; kp += k[23]; kp += k[0]; kp += k[4];
	kp += k[2]; kp += k[27]; kp += k[14]; kp += k[5]; kp += k[20]; kp += k[9];
	kp += k[22]; kp += k[18]; kp += k[11]; kp += k[3]; kp += k[25]; kp += k[7];
	kp += k[15]; kp += k[6]; kp += k[26]; kp += k[19]; kp += k[12]; kp += k[1];
	kp += k[40]; kp += k[51]; kp += k[30]; kp += k[36]; kp += k[46]; kp += k[54];
	kp += k[29]; kp += k[39]; kp += k[50]; kp += k[44]; kp += k[32]; kp += k[47];
	kp += k[43]; kp += k[48]; kp += k[38]; kp += k[55]; kp += k[33]; kp += k[52];
	kp += k[45]; kp += k[41]; kp += k[49]; kp += k[35]; kp += k[28]; kp += k[31];
	return kp;
}
string IP(string m)
{
	string mp = "", m_b = ""; // m_b is the binary representation of the message
	m_b = str2b(m);
	mp = m_b[57]; mp += m_b[49]; mp += m_b[41]; mp += m_b[33]; mp += m_b[25]; mp += m_b[17]; mp += m_b[9]; mp += m_b[1];
	mp += m_b[59]; mp += m_b[51]; mp += m_b[43]; mp += m_b[35]; mp += m_b[27]; mp += m_b[19]; mp += m_b[11]; mp += m_b[3];
	mp += m_b[61]; mp += m_b[53]; mp += m_b[45]; mp += m_b[37]; mp += m_b[29]; mp += m_b[21]; mp += m_b[13]; mp += m_b[5];
	mp += m_b[63]; mp += m_b[55]; mp += m_b[47]; mp += m_b[39]; mp += m_b[31]; mp += m_b[23]; mp += m_b[15]; mp += m_b[7];
	mp += m_b[56]; mp += m_b[48]; mp += m_b[40]; mp += m_b[32]; mp += m_b[24]; mp += m_b[16]; mp += m_b[8]; mp += m_b[0];
	mp += m_b[58]; mp += m_b[50]; mp += m_b[42]; mp += m_b[34]; mp += m_b[26]; mp += m_b[18]; mp += m_b[10]; mp += m_b[2];
	mp += m_b[60]; mp += m_b[52]; mp += m_b[44]; mp += m_b[36]; mp += m_b[28]; mp += m_b[20]; mp += m_b[12]; mp += m_b[4];
	mp += m_b[62]; mp += m_b[54]; mp += m_b[46]; mp += m_b[38]; mp += m_b[30]; mp += m_b[22]; mp += m_b[14]; mp += m_b[6];
	return mp;
}
string P(string m)
{
	string mp = "";
	mp = m[15]; mp += m[6]; mp += m[19]; mp += m[20];
	mp += m[28]; mp += m[11]; mp += m[27]; mp += m[16];
	mp += m[0]; mp += m[14]; mp += m[22]; mp += m[25];
	mp += m[4]; mp += m[17]; mp += m[30]; mp += m[9];
	mp += m[1]; mp += m[7]; mp += m[23]; mp += m[13];
	mp += m[31]; mp += m[26]; mp += m[2]; mp += m[8];
	mp += m[18]; mp += m[12]; mp += m[29]; mp += m[5];
	mp += m[21]; mp += m[10]; mp += m[3]; mp += m[24];
	return mp;
}
string IP_1(string m)
{
	string mp = "";
	mp = m[39]; mp += m[7]; mp += m[47]; mp += m[15]; mp += m[55]; mp += m[23]; mp += m[63]; mp += m[31];
	mp += m[38]; mp += m[6]; mp += m[46]; mp += m[14]; mp += m[54]; mp += m[22]; mp += m[62]; mp += m[30];
	mp += m[37]; mp += m[5]; mp += m[45]; mp += m[13]; mp += m[53]; mp += m[21]; mp += m[61]; mp += m[29];
	mp += m[36]; mp += m[4]; mp += m[44]; mp += m[12]; mp += m[52]; mp += m[20]; mp += m[60]; mp += m[28];
	mp += m[35]; mp += m[3]; mp += m[43]; mp += m[11]; mp += m[51]; mp += m[19]; mp += m[59]; mp += m[27];
	mp += m[34]; mp += m[2]; mp += m[42]; mp += m[10]; mp += m[50]; mp += m[18]; mp += m[58]; mp += m[26];
	mp += m[33]; mp += m[1]; mp += m[41]; mp += m[9]; mp += m[49]; mp += m[17]; mp += m[57]; mp += m[25];
	mp += m[32]; mp += m[0]; mp += m[40]; mp += m[8]; mp += m[48]; mp += m[16]; mp += m[56]; mp += m[24];
	return mp;
}
string expand(string R_str) // expand the right part of the message into 48 bits instead of 32 bits
{
	string R_str_e = "";
	R_str_e = R_str[31]; R_str_e += R_str[0]; R_str_e += R_str[1]; R_str_e += R_str[2]; R_str_e += R_str[3]; R_str_e += R_str[4];
	R_str_e += R_str[3]; R_str_e += R_str[4]; R_str_e += R_str[5]; R_str_e += R_str[6]; R_str_e += R_str[7]; R_str_e += R_str[8];
	R_str_e += R_str[7]; R_str_e += R_str[8]; R_str_e += R_str[9]; R_str_e += R_str[10]; R_str_e += R_str[11]; R_str_e += R_str[12];
	R_str_e += R_str[11]; R_str_e += R_str[12]; R_str_e += R_str[13]; R_str_e += R_str[14]; R_str_e += R_str[15]; R_str_e += R_str[16];
	R_str_e += R_str[15]; R_str_e += R_str[16]; R_str_e += R_str[17]; R_str_e += R_str[18]; R_str_e += R_str[19]; R_str_e += R_str[20];
	R_str_e += R_str[19]; R_str_e += R_str[20]; R_str_e += R_str[21]; R_str_e += R_str[22]; R_str_e += R_str[23]; R_str_e += R_str[24];
	R_str_e += R_str[23]; R_str_e += R_str[24]; R_str_e += R_str[25]; R_str_e += R_str[26]; R_str_e += R_str[27]; R_str_e += R_str[28];
	R_str_e += R_str[27]; R_str_e += R_str[28]; R_str_e += R_str[29]; R_str_e += R_str[30]; R_str_e += R_str[31]; R_str_e += R_str[0];
	return R_str_e;
}
void key_rounds(string full, string arr_pc2[])//hd5alaha string array fadya 34an temlaha
{
	string key_56 = "", left = "", right = "", arr_left[16], arr_right[16], arr_total[16];
	key_56 = PC1(full); // 56-bit key
	left = getStringLeft(key_56); // left part of the key
	right = getStringRight(key_56); // right part of the key
	arr_left[0] = shift_left(left);
	arr_left[1] = shift_left(arr_left[0]);
	arr_left[2] = double_shift_left(arr_left[1]);
	arr_left[3] = double_shift_left(arr_left[2]);
	arr_left[4] = double_shift_left(arr_left[3]);
	arr_left[5] = double_shift_left(arr_left[4]);
	arr_left[6] = double_shift_left(arr_left[5]);
	arr_left[7] = double_shift_left(arr_left[6]);
	arr_left[8] = shift_left(arr_left[7]);
	arr_left[9] = double_shift_left(arr_left[8]);
	arr_left[10] = double_shift_left(arr_left[9]);
	arr_left[11] = double_shift_left(arr_left[10]);
	arr_left[12] = double_shift_left(arr_left[11]);
	arr_left[13] = double_shift_left(arr_left[12]);
	arr_left[14] = double_shift_left(arr_left[13]);
	arr_left[15] = shift_left(arr_left[14]);
	for (int i = 0; i < 16; i++) // initializing array of concatenated key
	{
		arr_total[i] = arr_left[i];
	}
	arr_right[0] = shift_left(right);
	arr_right[1] = shift_left(arr_right[0]);
	arr_right[2] = double_shift_left(arr_right[1]);
	arr_right[3] = double_shift_left(arr_right[2]);
	arr_right[4] = double_shift_left(arr_right[3]);
	arr_right[5] = double_shift_left(arr_right[4]);
	arr_right[6] = double_shift_left(arr_right[5]);
	arr_right[7] = double_shift_left(arr_right[6]);
	arr_right[8] = shift_left(arr_right[7]);
	arr_right[9] = double_shift_left(arr_right[8]);
	arr_right[10] = double_shift_left(arr_right[9]);
	arr_right[11] = double_shift_left(arr_right[10]);
	arr_right[12] = double_shift_left(arr_right[11]);
	arr_right[13] = double_shift_left(arr_right[12]);
	arr_right[14] = double_shift_left(arr_right[13]);
	arr_right[15] = shift_left(arr_right[14]);
	for (int i = 0; i < 16; i++) // forming array of concatenated key
	{
		arr_total[i] += arr_right[i];
	}
	for (int i = 0; i < 16; i++) // 48-bit sub-keys
	{
		arr_pc2[i] += PC2(arr_total[i]);
	}
}
string sbox(string s_48) // returns 32 bits instead of 48 bits
{
	string sboxs[8], s_32 = "";
	
	// S-box1:
	for (int i = 0; i < 6; i++)
	{
		sboxs[0] += s_48[i];
	}
	if (sboxs[0] == "000000")sboxs[0] = "1110"; else if (sboxs[0] == "000001")sboxs[0] = "0000"; else if (sboxs[0] == "100000")sboxs[0] = "0100";
	else if (sboxs[0] == "100001")sboxs[0] = "1111"; else if (sboxs[0] == "000010")sboxs[0] = "0100"; else if (sboxs[0] == "000011")sboxs[0] = "1111";
	else if (sboxs[0] == "100010")sboxs[0] = "0001"; else if (sboxs[0] == "100011")sboxs[0] = "1100"; else if (sboxs[0] == "000100")sboxs[0] = "1101";
	else if (sboxs[0] == "000101")sboxs[0] = "0111"; else if (sboxs[0] == "100100")sboxs[0] = "1110"; else if (sboxs[0] == "100101")sboxs[0] = "1000";
	else if (sboxs[0] == "000110")sboxs[0] = "0001"; else if (sboxs[0] == "000111")sboxs[0] = "0100"; else if (sboxs[0] == "100110")sboxs[0] = "1000";
	else if (sboxs[0] == "100111")sboxs[0] = "0010"; else if (sboxs[0] == "001000")sboxs[0] = "0010"; else if (sboxs[0] == "001001")sboxs[0] = "1110";
	else if (sboxs[0] == "101000")sboxs[0] = "1101"; else if (sboxs[0] == "101001")sboxs[0] = "0100"; else if (sboxs[0] == "001010")sboxs[0] = "1111";
	else if (sboxs[0] == "001011")sboxs[0] = "0010"; else if (sboxs[0] == "101010")sboxs[0] = "0110"; else if (sboxs[0] == "101011")sboxs[0] = "1001";
	else if (sboxs[0] == "001100")sboxs[0] = "1011"; else if (sboxs[0] == "001101")sboxs[0] = "1101"; else if (sboxs[0] == "101100")sboxs[0] = "0010";
	else if (sboxs[0] == "101101")sboxs[0] = "0001"; else if (sboxs[0] == "001110")sboxs[0] = "1000"; else if (sboxs[0] == "001111")sboxs[0] = "0001";
	else if (sboxs[0] == "101110")sboxs[0] = "1011"; else if (sboxs[0] == "101111")sboxs[0] = "0111"; else if (sboxs[0] == "010000")sboxs[0] = "0011";
	else if (sboxs[0] == "010001")sboxs[0] = "1010"; else if (sboxs[0] == "110000")sboxs[0] = "1111"; else if (sboxs[0] == "110001")sboxs[0] = "0101";
	else if (sboxs[0] == "010010")sboxs[0] = "1010"; else if (sboxs[0] == "010011")sboxs[0] = "0110"; else if (sboxs[0] == "110010")sboxs[0] = "1100";
	else if (sboxs[0] == "110011")sboxs[0] = "1011"; else if (sboxs[0] == "010100")sboxs[0] = "0110"; else if (sboxs[0] == "010101")sboxs[0] = "1100";
	else if (sboxs[0] == "110100")sboxs[0] = "1001"; else if (sboxs[0] == "110101")sboxs[0] = "0011"; else if (sboxs[0] == "010110")sboxs[0] = "1100";
	else if (sboxs[0] == "010111")sboxs[0] = "1011"; else if (sboxs[0] == "110110")sboxs[0] = "0111"; else if (sboxs[0] == "110111")sboxs[0] = "1110";
	else if (sboxs[0] == "011000")sboxs[0] = "0101"; else if (sboxs[0] == "011001")sboxs[0] = "1001"; else if (sboxs[0] == "111000")sboxs[0] = "0011";
	else if (sboxs[0] == "111001")sboxs[0] = "1010"; else if (sboxs[0] == "011010")sboxs[0] = "1001"; else if (sboxs[0] == "011011")sboxs[0] = "0101";
	else if (sboxs[0] == "111010")sboxs[0] = "1010"; else if (sboxs[0] == "111011")sboxs[0] = "0000"; else if (sboxs[0] == "011100")sboxs[0] = "0000";
	else if (sboxs[0] == "011101")sboxs[0] = "0011"; else if (sboxs[0] == "111100")sboxs[0] = "0101"; else if (sboxs[0] == "111101")sboxs[0] = "0110";
	else if (sboxs[0] == "011110")sboxs[0] = "0111"; else if (sboxs[0] == "011111")sboxs[0] = "1000"; else if (sboxs[0] == "111110")sboxs[0] = "0000";
	else if (sboxs[0] == "111111")sboxs[0] = "1101";

	// S-box2:
	for (int i = 6; i < 12; i++)
	{
		sboxs[1] += s_48[i];
	}
	if (sboxs[1] == "000000")sboxs[1] = "1111"; else if (sboxs[1] == "000001")sboxs[1] = "0011"; else if (sboxs[1] == "100000")sboxs[1] = "0000";
	else if (sboxs[1] == "100001")sboxs[1] = "1101"; else if (sboxs[1] == "000010")sboxs[1] = "0001"; else if (sboxs[1] == "000011")sboxs[1] = "1101";
	else if (sboxs[1] == "100010")sboxs[1] = "1110"; else if (sboxs[1] == "100011")sboxs[1] = "1000"; else if (sboxs[1] == "000100")sboxs[1] = "1000";
	else if (sboxs[1] == "000101")sboxs[1] = "0100"; else if (sboxs[1] == "100100")sboxs[1] = "0111"; else if (sboxs[1] == "100101")sboxs[1] = "1010";
	else if (sboxs[1] == "000110")sboxs[1] = "1110"; else if (sboxs[1] == "000111")sboxs[1] = "0111"; else if (sboxs[1] == "100110")sboxs[1] = "1011";
	else if (sboxs[1] == "100111")sboxs[1] = "0001"; else if (sboxs[1] == "001000")sboxs[1] = "0110"; else if (sboxs[1] == "001001")sboxs[1] = "1111";
	else if (sboxs[1] == "101000")sboxs[1] = "1010"; else if (sboxs[1] == "101001")sboxs[1] = "0011"; else if (sboxs[1] == "001010")sboxs[1] = "1011";
	else if (sboxs[1] == "001011")sboxs[1] = "0010"; else if (sboxs[1] == "101010")sboxs[1] = "0100"; else if (sboxs[1] == "101011")sboxs[1] = "1111";
	else if (sboxs[1] == "001100")sboxs[1] = "0011"; else if (sboxs[1] == "001101")sboxs[1] = "1000"; else if (sboxs[1] == "101100")sboxs[1] = "1101";
	else if (sboxs[1] == "101101")sboxs[1] = "0100"; else if (sboxs[1] == "001110")sboxs[1] = "0100"; else if (sboxs[1] == "001111")sboxs[1] = "1110";
	else if (sboxs[1] == "101110")sboxs[1] = "0001"; else if (sboxs[1] == "101111")sboxs[1] = "0010"; else if (sboxs[1] == "010000")sboxs[1] = "1001";
	else if (sboxs[1] == "010001")sboxs[1] = "1100"; else if (sboxs[1] == "110000")sboxs[1] = "0101"; else if (sboxs[1] == "110001")sboxs[1] = "1011";
	else if (sboxs[1] == "010010")sboxs[1] = "0111"; else if (sboxs[1] == "010011")sboxs[1] = "0000"; else if (sboxs[1] == "110010")sboxs[1] = "1000";
	else if (sboxs[1] == "110011")sboxs[1] = "0110"; else if (sboxs[1] == "010100")sboxs[1] = "0010"; else if (sboxs[1] == "010101")sboxs[1] = "0001";
	else if (sboxs[1] == "110100")sboxs[1] = "1100"; else if (sboxs[1] == "110101")sboxs[1] = "0111"; else if (sboxs[1] == "010110")sboxs[1] = "1101";
	else if (sboxs[1] == "010111")sboxs[1] = "1010"; else if (sboxs[1] == "110110")sboxs[1] = "0110"; else if (sboxs[1] == "110111")sboxs[1] = "1100";
	else if (sboxs[1] == "011000")sboxs[1] = "1100"; else if (sboxs[1] == "011001")sboxs[1] = "0110"; else if (sboxs[1] == "111000")sboxs[1] = "1001";
	else if (sboxs[1] == "111001")sboxs[1] = "0000"; else if (sboxs[1] == "011010")sboxs[1] = "0000"; else if (sboxs[1] == "011011")sboxs[1] = "1001";
	else if (sboxs[1] == "111010")sboxs[1] = "0011"; else if (sboxs[1] == "111011")sboxs[1] = "0101"; else if (sboxs[1] == "011100")sboxs[1] = "0101";
	else if (sboxs[1] == "011101")sboxs[1] = "1011"; else if (sboxs[1] == "111100")sboxs[1] = "0010"; else if (sboxs[1] == "111101")sboxs[1] = "1110";
	else if (sboxs[1] == "011110")sboxs[1] = "1010"; else if (sboxs[1] == "011111")sboxs[1] = "0101"; else if (sboxs[1] == "111110")sboxs[1] = "1111";
	else if (sboxs[1] == "111111")sboxs[1] = "1001";


	// S-box3:
	for (int i = 12; i < 18; i++)
	{
		sboxs[2] += s_48[i];
	}
	if (sboxs[2] == "000000")sboxs[2] = "1010"; else if (sboxs[2] == "000001")sboxs[2] = "1101"; else if (sboxs[2] == "100000")sboxs[2] = "1101";
	else if (sboxs[2] == "100001")sboxs[2] = "0001"; else if (sboxs[2] == "000010")sboxs[2] = "0000"; else if (sboxs[2] == "000011")sboxs[2] = "0111";
	else if (sboxs[2] == "100010")sboxs[2] = "0110"; else if (sboxs[2] == "100011")sboxs[2] = "1010"; else if (sboxs[2] == "000100")sboxs[2] = "1001";
	else if (sboxs[2] == "000101")sboxs[2] = "0000"; else if (sboxs[2] == "100100")sboxs[2] = "0100"; else if (sboxs[2] == "100101")sboxs[2] = "1101";
	else if (sboxs[2] == "000110")sboxs[2] = "1110"; else if (sboxs[2] == "000111")sboxs[2] = "1001"; else if (sboxs[2] == "100110")sboxs[2] = "1001";
	else if (sboxs[2] == "100111")sboxs[2] = "0000"; else if (sboxs[2] == "001000")sboxs[2] = "0110"; else if (sboxs[2] == "001001")sboxs[2] = "0011";
	else if (sboxs[2] == "101000")sboxs[2] = "1000"; else if (sboxs[2] == "101001")sboxs[2] = "0110"; else if (sboxs[2] == "001010")sboxs[2] = "0011";
	else if (sboxs[2] == "001011")sboxs[2] = "0100"; else if (sboxs[2] == "101010")sboxs[2] = "1111"; else if (sboxs[2] == "101011")sboxs[2] = "1001";
	else if (sboxs[2] == "001100")sboxs[2] = "1111"; else if (sboxs[2] == "001101")sboxs[2] = "0110"; else if (sboxs[2] == "101100")sboxs[2] = "0011";
	else if (sboxs[2] == "101101")sboxs[2] = "1000"; else if (sboxs[2] == "001110")sboxs[2] = "0101"; else if (sboxs[2] == "001111")sboxs[2] = "1010";
	else if (sboxs[2] == "101110")sboxs[2] = "0000"; else if (sboxs[2] == "101111")sboxs[2] = "0111"; else if (sboxs[2] == "010000")sboxs[2] = "0001";
	else if (sboxs[2] == "010001")sboxs[2] = "0010"; else if (sboxs[2] == "110000")sboxs[2] = "1011"; else if (sboxs[2] == "110001")sboxs[2] = "0100";
	else if (sboxs[2] == "010010")sboxs[2] = "1101"; else if (sboxs[2] == "010011")sboxs[2] = "1000"; else if (sboxs[2] == "110010")sboxs[2] = "0001";
	else if (sboxs[2] == "110011")sboxs[2] = "1111"; else if (sboxs[2] == "010100")sboxs[2] = "1100"; else if (sboxs[2] == "010101")sboxs[2] = "0101";
	else if (sboxs[2] == "110100")sboxs[2] = "0010"; else if (sboxs[2] == "110101")sboxs[2] = "1110"; else if (sboxs[2] == "010110")sboxs[2] = "0111";
	else if (sboxs[2] == "010111")sboxs[2] = "1110"; else if (sboxs[2] == "110110")sboxs[2] = "1100"; else if (sboxs[2] == "110111")sboxs[2] = "0011";
	else if (sboxs[2] == "011000")sboxs[2] = "1011"; else if (sboxs[2] == "011001")sboxs[2] = "1100"; else if (sboxs[2] == "111000")sboxs[2] = "0101";
	else if (sboxs[2] == "111001")sboxs[2] = "1011"; else if (sboxs[2] == "011010")sboxs[2] = "0100"; else if (sboxs[2] == "011011")sboxs[2] = "1011";
	else if (sboxs[2] == "111010")sboxs[2] = "1010"; else if (sboxs[2] == "111011")sboxs[2] = "0101"; else if (sboxs[2] == "011100")sboxs[2] = "0010";
	else if (sboxs[2] == "011101")sboxs[2] = "1111"; else if (sboxs[2] == "111100")sboxs[2] = "1110"; else if (sboxs[2] == "111101")sboxs[2] = "0010";
	else if (sboxs[2] == "011110")sboxs[2] = "1000"; else if (sboxs[2] == "011111")sboxs[2] = "0001"; else if (sboxs[2] == "111110")sboxs[2] = "0111";
	else if (sboxs[2] == "111111")sboxs[2] = "1100";

	// S-box4:
	for (int i = 18; i < 24; i++)
	{
		sboxs[3] += s_48[i];
	}
	if (sboxs[3] == "000000")sboxs[3] = "0111"; else if (sboxs[3] == "000001")sboxs[3] = "1101"; else if (sboxs[3] == "100000")sboxs[3] = "1010";
	else if (sboxs[3] == "100001")sboxs[3] = "0011"; else if (sboxs[3] == "000010")sboxs[3] = "1101"; else if (sboxs[3] == "000011")sboxs[3] = "1000";
	else if (sboxs[3] == "100010")sboxs[3] = "0110"; else if (sboxs[3] == "100011")sboxs[3] = "1111"; else if (sboxs[3] == "000100")sboxs[3] = "1110";
	else if (sboxs[3] == "000101")sboxs[3] = "1011"; else if (sboxs[3] == "100100")sboxs[3] = "1001"; else if (sboxs[3] == "100101")sboxs[3] = "0000";
	else if (sboxs[3] == "000110")sboxs[3] = "0011"; else if (sboxs[3] == "000111")sboxs[3] = "0101"; else if (sboxs[3] == "100110")sboxs[3] = "0000";
	else if (sboxs[3] == "100111")sboxs[3] = "0110"; else if (sboxs[3] == "001000")sboxs[3] = "0000"; else if (sboxs[3] == "001001")sboxs[3] = "0110";
	else if (sboxs[3] == "101000")sboxs[3] = "1100"; else if (sboxs[3] == "101001")sboxs[3] = "1010"; else if (sboxs[3] == "001010")sboxs[3] = "0110";
	else if (sboxs[3] == "001011")sboxs[3] = "1111"; else if (sboxs[3] == "101010")sboxs[3] = "1011"; else if (sboxs[3] == "101011")sboxs[3] = "0001";
	else if (sboxs[3] == "001100")sboxs[3] = "1001"; else if (sboxs[3] == "001101")sboxs[3] = "0000"; else if (sboxs[3] == "101100")sboxs[3] = "0111";
	else if (sboxs[3] == "101101")sboxs[3] = "1101"; else if (sboxs[3] == "001110")sboxs[3] = "1010"; else if (sboxs[3] == "001111")sboxs[3] = "0011";
	else if (sboxs[3] == "101110")sboxs[3] = "1101"; else if (sboxs[3] == "101111")sboxs[3] = "1000"; else if (sboxs[3] == "010000")sboxs[3] = "0001";
	else if (sboxs[3] == "010001")sboxs[3] = "0100"; else if (sboxs[3] == "110000")sboxs[3] = "1111"; else if (sboxs[3] == "110001")sboxs[3] = "1001";
	else if (sboxs[3] == "010010")sboxs[3] = "0010"; else if (sboxs[3] == "010011")sboxs[3] = "0111"; else if (sboxs[3] == "110010")sboxs[3] = "0001";
	else if (sboxs[3] == "110011")sboxs[3] = "0100"; else if (sboxs[3] == "010100")sboxs[3] = "1000"; else if (sboxs[3] == "010101")sboxs[3] = "0010";
	else if (sboxs[3] == "110100")sboxs[3] = "0011"; else if (sboxs[3] == "110101")sboxs[3] = "0101"; else if (sboxs[3] == "010110")sboxs[3] = "0101";
	else if (sboxs[3] == "010111")sboxs[3] = "1100"; else if (sboxs[3] == "110110")sboxs[3] = "1110"; else if (sboxs[3] == "110111")sboxs[3] = "1011";
	else if (sboxs[3] == "011000")sboxs[3] = "1011"; else if (sboxs[3] == "011001")sboxs[3] = "0001"; else if (sboxs[3] == "111000")sboxs[3] = "0101";
	else if (sboxs[3] == "111001")sboxs[3] = "1100"; else if (sboxs[3] == "011010")sboxs[3] = "1100"; else if (sboxs[3] == "011011")sboxs[3] = "1010";
	else if (sboxs[3] == "111010")sboxs[3] = "0010"; else if (sboxs[3] == "111011")sboxs[3] = "0111"; else if (sboxs[3] == "011100")sboxs[3] = "0100";
	else if (sboxs[3] == "011101")sboxs[3] = "1110"; else if (sboxs[3] == "111100")sboxs[3] = "1000"; else if (sboxs[3] == "111101")sboxs[3] = "0010";
	else if (sboxs[3] == "011110")sboxs[3] = "1111"; else if (sboxs[3] == "011111")sboxs[3] = "1001"; else if (sboxs[3] == "111110")sboxs[3] = "0100";
	else if (sboxs[3] == "111111")sboxs[3] = "1110";


	// S-box5:
	for (int i = 24; i < 30; i++)
	{
		sboxs[4] += s_48[i];
	}
	if (sboxs[4] == "000000")sboxs[4] = "0010"; else if (sboxs[4] == "000001")sboxs[4] = "1110"; else if (sboxs[4] == "100000")sboxs[4] = "0100";
	else if (sboxs[4] == "100001")sboxs[4] = "1011"; else if (sboxs[4] == "000010")sboxs[4] = "1100"; else if (sboxs[4] == "000011")sboxs[4] = "1011";
	else if (sboxs[4] == "100010")sboxs[4] = "0010"; else if (sboxs[4] == "100011")sboxs[4] = "1000"; else if (sboxs[4] == "000100")sboxs[4] = "0100";
	else if (sboxs[4] == "000101")sboxs[4] = "0010"; else if (sboxs[4] == "100100")sboxs[4] = "0001"; else if (sboxs[4] == "100101")sboxs[4] = "1100";
	else if (sboxs[4] == "000110")sboxs[4] = "0001"; else if (sboxs[4] == "000111")sboxs[4] = "1100"; else if (sboxs[4] == "100110")sboxs[4] = "1011";
	else if (sboxs[4] == "100111")sboxs[4] = "0111"; else if (sboxs[4] == "001000")sboxs[4] = "0111"; else if (sboxs[4] == "001001")sboxs[4] = "0100";
	else if (sboxs[4] == "101000")sboxs[4] = "1010"; else if (sboxs[4] == "101001")sboxs[4] = "0001"; else if (sboxs[4] == "001010")sboxs[4] = "1010";
	else if (sboxs[4] == "001011")sboxs[4] = "0111"; else if (sboxs[4] == "101010")sboxs[4] = "1101"; else if (sboxs[4] == "101011")sboxs[4] = "1110";
	else if (sboxs[4] == "001100")sboxs[4] = "1011"; else if (sboxs[4] == "001101")sboxs[4] = "1101"; else if (sboxs[4] == "101100")sboxs[4] = "0111";
	else if (sboxs[4] == "101101")sboxs[4] = "0010"; else if (sboxs[4] == "001110")sboxs[4] = "0110"; else if (sboxs[4] == "001111")sboxs[4] = "0001";
	else if (sboxs[4] == "101110")sboxs[4] = "1000"; else if (sboxs[4] == "101111")sboxs[4] = "1101"; else if (sboxs[4] == "010000")sboxs[4] = "1000";
	else if (sboxs[4] == "010001")sboxs[4] = "0101"; else if (sboxs[4] == "110000")sboxs[4] = "1111"; else if (sboxs[4] == "110001")sboxs[4] = "0110";
	else if (sboxs[4] == "010010")sboxs[4] = "0101"; else if (sboxs[4] == "010011")sboxs[4] = "0000"; else if (sboxs[4] == "110010")sboxs[4] = "1001";
	else if (sboxs[4] == "110011")sboxs[4] = "1111"; else if (sboxs[4] == "010100")sboxs[4] = "0011"; else if (sboxs[4] == "010101")sboxs[4] = "1111";
	else if (sboxs[4] == "110100")sboxs[4] = "1100"; else if (sboxs[4] == "110101")sboxs[4] = "0000"; else if (sboxs[4] == "010110")sboxs[4] = "1111";
	else if (sboxs[4] == "010111")sboxs[4] = "1010"; else if (sboxs[4] == "110110")sboxs[4] = "0101"; else if (sboxs[4] == "110111")sboxs[4] = "1001";
	else if (sboxs[4] == "011000")sboxs[4] = "1101"; else if (sboxs[4] == "011001")sboxs[4] = "0011"; else if (sboxs[4] == "111000")sboxs[4] = "0110";
	else if (sboxs[4] == "111001")sboxs[4] = "1010"; else if (sboxs[4] == "011010")sboxs[4] = "0000"; else if (sboxs[4] == "011011")sboxs[4] = "1001";
	else if (sboxs[4] == "111010")sboxs[4] = "0011"; else if (sboxs[4] == "111011")sboxs[4] = "0100"; else if (sboxs[4] == "011100")sboxs[4] = "1110";
	else if (sboxs[4] == "011101")sboxs[4] = "1000"; else if (sboxs[4] == "111100")sboxs[4] = "0000"; else if (sboxs[4] == "111101")sboxs[4] = "0101";
	else if (sboxs[4] == "011110")sboxs[4] = "1001"; else if (sboxs[4] == "011111")sboxs[4] = "0110"; else if (sboxs[4] == "111110")sboxs[4] = "1110";
	else if (sboxs[4] == "111111")sboxs[4] = "0011";


	// S-box6:
	for (int i = 30; i < 36; i++)
	{
		sboxs[5] += s_48[i];
	}
	if (sboxs[5] == "000000")sboxs[5] = "1100"; else if (sboxs[5] == "000001")sboxs[5] = "1010"; else if (sboxs[5] == "100000")sboxs[5] = "1001";
	else if (sboxs[5] == "100001")sboxs[5] = "0100"; else if (sboxs[5] == "000010")sboxs[5] = "0001"; else if (sboxs[5] == "000011")sboxs[5] = "1111";
	else if (sboxs[5] == "100010")sboxs[5] = "1110"; else if (sboxs[5] == "100011")sboxs[5] = "0011"; else if (sboxs[5] == "000100")sboxs[5] = "1010";
	else if (sboxs[5] == "000101")sboxs[5] = "0100"; else if (sboxs[5] == "100100")sboxs[5] = "1111"; else if (sboxs[5] == "100101")sboxs[5] = "0010";
	else if (sboxs[5] == "000110")sboxs[5] = "1111"; else if (sboxs[5] == "000111")sboxs[5] = "0010"; else if (sboxs[5] == "100110")sboxs[5] = "0101";
	else if (sboxs[5] == "100111")sboxs[5] = "1100"; else if (sboxs[5] == "001000")sboxs[5] = "1001"; else if (sboxs[5] == "001001")sboxs[5] = "0111";
	else if (sboxs[5] == "101000")sboxs[5] = "0010"; else if (sboxs[5] == "101001")sboxs[5] = "1001"; else if (sboxs[5] == "001010")sboxs[5] = "0010";
	else if (sboxs[5] == "001011")sboxs[5] = "1100"; else if (sboxs[5] == "101010")sboxs[5] = "1000"; else if (sboxs[5] == "101011")sboxs[5] = "0101";
	else if (sboxs[5] == "001100")sboxs[5] = "0110"; else if (sboxs[5] == "001101")sboxs[5] = "1001"; else if (sboxs[5] == "101100")sboxs[5] = "1100";
	else if (sboxs[5] == "101101")sboxs[5] = "1111"; else if (sboxs[5] == "001110")sboxs[5] = "1000"; else if (sboxs[5] == "001111")sboxs[5] = "0101";
	else if (sboxs[5] == "101110")sboxs[5] = "0011"; else if (sboxs[5] == "101111")sboxs[5] = "1010"; else if (sboxs[5] == "010000")sboxs[5] = "0000";
	else if (sboxs[5] == "010001")sboxs[5] = "0110"; else if (sboxs[5] == "110000")sboxs[5] = "0111"; else if (sboxs[5] == "110001")sboxs[5] = "1011";
	else if (sboxs[5] == "010010")sboxs[5] = "1101"; else if (sboxs[5] == "010011")sboxs[5] = "0001"; else if (sboxs[5] == "110010")sboxs[5] = "0000";
	else if (sboxs[5] == "110011")sboxs[5] = "1110"; else if (sboxs[5] == "010100")sboxs[5] = "0011"; else if (sboxs[5] == "010101")sboxs[5] = "1101";
	else if (sboxs[5] == "110100")sboxs[5] = "0100"; else if (sboxs[5] == "110101")sboxs[5] = "0001"; else if (sboxs[5] == "010110")sboxs[5] = "0100";
	else if (sboxs[5] == "010111")sboxs[5] = "1110"; else if (sboxs[5] == "110110")sboxs[5] = "1010"; else if (sboxs[5] == "110111")sboxs[5] = "0111";
	else if (sboxs[5] == "011000")sboxs[5] = "1110"; else if (sboxs[5] == "011001")sboxs[5] = "0000"; else if (sboxs[5] == "111000")sboxs[5] = "0001";
	else if (sboxs[5] == "111001")sboxs[5] = "0110"; else if (sboxs[5] == "011010")sboxs[5] = "0111"; else if (sboxs[5] == "011011")sboxs[5] = "1011";
	else if (sboxs[5] == "111010")sboxs[5] = "1101"; else if (sboxs[5] == "111011")sboxs[5] = "0000"; else if (sboxs[5] == "011100")sboxs[5] = "0101";
	else if (sboxs[5] == "011101")sboxs[5] = "0011"; else if (sboxs[5] == "111100")sboxs[5] = "1011"; else if (sboxs[5] == "111101")sboxs[5] = "1000";
	else if (sboxs[5] == "011110")sboxs[5] = "1011"; else if (sboxs[5] == "011111")sboxs[5] = "1000"; else if (sboxs[5] == "111110")sboxs[5] = "0110";
	else if (sboxs[5] == "111111")sboxs[5] = "1101";


	// S-box7:
	for (int i = 36; i < 42; i++)
	{
		sboxs[6] += s_48[i];
	}
	if (sboxs[6] == "000000")sboxs[6] = "0100"; else if (sboxs[6] == "000001")sboxs[6] = "1101"; else if (sboxs[6] == "100000")sboxs[6] = "0001";
	else if (sboxs[6] == "100001")sboxs[6] = "0110"; else if (sboxs[6] == "000010")sboxs[6] = "1011"; else if (sboxs[6] == "000011")sboxs[6] = "0000";
	else if (sboxs[6] == "100010")sboxs[6] = "0100"; else if (sboxs[6] == "100011")sboxs[6] = "1011"; else if (sboxs[6] == "000100")sboxs[6] = "0010";
	else if (sboxs[6] == "000101")sboxs[6] = "1011"; else if (sboxs[6] == "100100")sboxs[6] = "1011"; else if (sboxs[6] == "100101")sboxs[6] = "1101";
	else if (sboxs[6] == "000110")sboxs[6] = "1110"; else if (sboxs[6] == "000111")sboxs[6] = "0111"; else if (sboxs[6] == "100110")sboxs[6] = "1101";
	else if (sboxs[6] == "100111")sboxs[6] = "1000"; else if (sboxs[6] == "001000")sboxs[6] = "1111"; else if (sboxs[6] == "001001")sboxs[6] = "0100";
	else if (sboxs[6] == "101000")sboxs[6] = "1100"; else if (sboxs[6] == "101001")sboxs[6] = "0001"; else if (sboxs[6] == "001010")sboxs[6] = "0000";
	else if (sboxs[6] == "001011")sboxs[6] = "1001"; else if (sboxs[6] == "101010")sboxs[6] = "0011"; else if (sboxs[6] == "101011")sboxs[6] = "0100";
	else if (sboxs[6] == "001100")sboxs[6] = "1000"; else if (sboxs[6] == "001101")sboxs[6] = "0001"; else if (sboxs[6] == "101100")sboxs[6] = "0111";
	else if (sboxs[6] == "101101")sboxs[6] = "1010"; else if (sboxs[6] == "001110")sboxs[6] = "1101"; else if (sboxs[6] == "001111")sboxs[6] = "1010";
	else if (sboxs[6] == "101110")sboxs[6] = "1110"; else if (sboxs[6] == "101111")sboxs[6] = "0111"; else if (sboxs[6] == "010000")sboxs[6] = "0011";
	else if (sboxs[6] == "010001")sboxs[6] = "1110"; else if (sboxs[6] == "110000")sboxs[6] = "1010"; else if (sboxs[6] == "110001")sboxs[6] = "1001";
	else if (sboxs[6] == "010010")sboxs[6] = "1100"; else if (sboxs[6] == "010011")sboxs[6] = "0011"; else if (sboxs[6] == "110010")sboxs[6] = "1111";
	else if (sboxs[6] == "110011")sboxs[6] = "0101"; else if (sboxs[6] == "010100")sboxs[6] = "1001"; else if (sboxs[6] == "010101")sboxs[6] = "0101";
	else if (sboxs[6] == "110100")sboxs[6] = "0110"; else if (sboxs[6] == "110101")sboxs[6] = "0000"; else if (sboxs[6] == "010110")sboxs[6] = "0111";
	else if (sboxs[6] == "010111")sboxs[6] = "1100"; else if (sboxs[6] == "110110")sboxs[6] = "1000"; else if (sboxs[6] == "110111")sboxs[6] = "1111";
	else if (sboxs[6] == "011000")sboxs[6] = "0101"; else if (sboxs[6] == "011001")sboxs[6] = "0010"; else if (sboxs[6] == "111000")sboxs[6] = "0000";
	else if (sboxs[6] == "111001")sboxs[6] = "1110"; else if (sboxs[6] == "011010")sboxs[6] = "1010"; else if (sboxs[6] == "011011")sboxs[6] = "1111";
	else if (sboxs[6] == "111010")sboxs[6] = "0101"; else if (sboxs[6] == "111011")sboxs[6] = "0010"; else if (sboxs[6] == "011100")sboxs[6] = "0110";
	else if (sboxs[6] == "011101")sboxs[6] = "1000"; else if (sboxs[6] == "111100")sboxs[6] = "1001"; else if (sboxs[6] == "111101")sboxs[6] = "0011";
	else if (sboxs[6] == "011110")sboxs[6] = "0001"; else if (sboxs[6] == "011111")sboxs[6] = "0110"; else if (sboxs[6] == "111110")sboxs[6] = "0010";
	else if (sboxs[6] == "111111")sboxs[6] = "1100";


	// S-box8:
	for (int i = 42; i < 48; i++)
	{
		sboxs[7] += s_48[i];
	}
	if (sboxs[7] == "000000")sboxs[7] = "1101"; else if (sboxs[7] == "000001")sboxs[7] = "0001"; else if (sboxs[7] == "100000")sboxs[7] = "0111";
	else if (sboxs[7] == "100001")sboxs[7] = "0010"; else if (sboxs[7] == "000010")sboxs[7] = "0010"; else if (sboxs[7] == "000011")sboxs[7] = "1111";
	else if (sboxs[7] == "100010")sboxs[7] = "1011"; else if (sboxs[7] == "100011")sboxs[7] = "0001"; else if (sboxs[7] == "000100")sboxs[7] = "1000";
	else if (sboxs[7] == "000101")sboxs[7] = "1101"; else if (sboxs[7] == "100100")sboxs[7] = "0100"; else if (sboxs[7] == "100101")sboxs[7] = "1110";
	else if (sboxs[7] == "000110")sboxs[7] = "0100"; else if (sboxs[7] == "000111")sboxs[7] = "1000"; else if (sboxs[7] == "100110")sboxs[7] = "0001";
	else if (sboxs[7] == "100111")sboxs[7] = "0111"; else if (sboxs[7] == "001000")sboxs[7] = "0110"; else if (sboxs[7] == "001001")sboxs[7] = "1010";
	else if (sboxs[7] == "101000")sboxs[7] = "1001"; else if (sboxs[7] == "101001")sboxs[7] = "0100"; else if (sboxs[7] == "001010")sboxs[7] = "1111";
	else if (sboxs[7] == "001011")sboxs[7] = "0011"; else if (sboxs[7] == "101010")sboxs[7] = "1100"; else if (sboxs[7] == "101011")sboxs[7] = "1010";
	else if (sboxs[7] == "001100")sboxs[7] = "1011"; else if (sboxs[7] == "001101")sboxs[7] = "0111"; else if (sboxs[7] == "101100")sboxs[7] = "1110";
	else if (sboxs[7] == "101101")sboxs[7] = "1000"; else if (sboxs[7] == "001110")sboxs[7] = "0001"; else if (sboxs[7] == "001111")sboxs[7] = "0100";
	else if (sboxs[7] == "101110")sboxs[7] = "0010"; else if (sboxs[7] == "101111")sboxs[7] = "1101"; else if (sboxs[7] == "010000")sboxs[7] = "1010";
	else if (sboxs[7] == "010001")sboxs[7] = "1100"; else if (sboxs[7] == "110000")sboxs[7] = "0000"; else if (sboxs[7] == "110001")sboxs[7] = "1111";
	else if (sboxs[7] == "010010")sboxs[7] = "1001"; else if (sboxs[7] == "010011")sboxs[7] = "0101"; else if (sboxs[7] == "110010")sboxs[7] = "0110";
	else if (sboxs[7] == "110011")sboxs[7] = "1100"; else if (sboxs[7] == "010100")sboxs[7] = "0011"; else if (sboxs[7] == "010101")sboxs[7] = "0110";
	else if (sboxs[7] == "110100")sboxs[7] = "1010"; else if (sboxs[7] == "110101")sboxs[7] = "1001"; else if (sboxs[7] == "010110")sboxs[7] = "1110";
	else if (sboxs[7] == "010111")sboxs[7] = "1011"; else if (sboxs[7] == "110110")sboxs[7] = "1101"; else if (sboxs[7] == "110111")sboxs[7] = "0000";
	else if (sboxs[7] == "011000")sboxs[7] = "0101"; else if (sboxs[7] == "011001")sboxs[7] = "0000"; else if (sboxs[7] == "111000")sboxs[7] = "1111";
	else if (sboxs[7] == "111001")sboxs[7] = "0011"; else if (sboxs[7] == "011010")sboxs[7] = "0000"; else if (sboxs[7] == "011011")sboxs[7] = "1110";
	else if (sboxs[7] == "111010")sboxs[7] = "0011"; else if (sboxs[7] == "111011")sboxs[7] = "0101"; else if (sboxs[7] == "011100")sboxs[7] = "1100";
	else if (sboxs[7] == "011101")sboxs[7] = "1001"; else if (sboxs[7] == "111100")sboxs[7] = "0101"; else if (sboxs[7] == "111101")sboxs[7] = "0110";
	else if (sboxs[7] == "011110")sboxs[7] = "0111"; else if (sboxs[7] == "011111")sboxs[7] = "0010"; else if (sboxs[7] == "111110")sboxs[7] = "1000";
	else if (sboxs[7] == "111111")sboxs[7] = "1011";

	for (int i = 0; i < 8; i++) // convert 48 bits into 32 bits
	{
		s_32 += sboxs[i];
	}
	return s_32;
}
string des_round(string Ri, string Kn)
{
	string des = "", des2 = "";
	string r = expand(Ri);
	des = XOR(r, Kn);
	des2 = sbox(des);
	return P(des2);
}
string encrypt(string full_msg, string original_key)
{
	string msg = "", l_msg = "", r_msg = "", msg_left[16], msg_right[16], concat_key[16];
	string swapped = "";
	for (int i = 0; i < 16; i++)
	{
		concat_key[i] = "";
	}
	key_rounds(original_key, concat_key);
	msg = IP(full_msg);
	l_msg = getStringLeft(msg); // left part of the message
	r_msg = getStringRight(msg); // right part of the message

	msg_left[0] = r_msg;
	msg_right[0] = XOR(l_msg, des_round(r_msg, concat_key[0]));

	msg_left[1] = msg_right[0];
	msg_right[1] = XOR(msg_left[0], des_round(msg_right[0], concat_key[1]));

	msg_left[2] = msg_right[1];
	msg_right[2] = XOR(msg_left[1], des_round(msg_right[1], concat_key[2]));

	msg_left[3] = msg_right[2];
	msg_right[3] = XOR(msg_left[2], des_round(msg_right[2], concat_key[3]));

	msg_left[4] = msg_right[3];
	msg_right[4] = XOR(msg_left[3], des_round(msg_right[3], concat_key[4]));

	msg_left[5] = msg_right[4];
	msg_right[5] = XOR(msg_left[4], des_round(msg_right[4], concat_key[5]));

	msg_left[6] = msg_right[5];
	msg_right[6] = XOR(msg_left[5], des_round(msg_right[5], concat_key[6]));

	msg_left[7] = msg_right[6];
	msg_right[7] = XOR(msg_left[6], des_round(msg_right[6], concat_key[7]));

	msg_left[8] = msg_right[7];
	msg_right[8] = XOR(msg_left[7], des_round(msg_right[7], concat_key[8]));

	msg_left[9] = msg_right[8];
	msg_right[9] = XOR(msg_left[8], des_round(msg_right[8], concat_key[9]));

	msg_left[10] = msg_right[9];
	msg_right[10] = XOR(msg_left[9], des_round(msg_right[9], concat_key[10]));

	msg_left[11] = msg_right[10];
	msg_right[11] = XOR(msg_left[10], des_round(msg_right[10], concat_key[11]));

	msg_left[12] = msg_right[11];
	msg_right[12] = XOR(msg_left[11], des_round(msg_right[11], concat_key[12]));

	msg_left[13] = msg_right[12];
	msg_right[13] = XOR(msg_left[12], des_round(msg_right[12], concat_key[13]));

	msg_left[14] = msg_right[13];
	msg_right[14] = XOR(msg_left[13], des_round(msg_right[13], concat_key[14]));

	msg_left[15] = msg_right[14];
	msg_right[15] = XOR(msg_left[14], des_round(msg_right[14], concat_key[15]));

	swapped = msg_right[15];
	swapped += msg_left[15];

	return b2hex(IP_1(swapped));
}
string decrypt(string full_msg, string original_key)
{
	string msg = "", l_msg = "", r_msg = "", msg_left[16], msg_right[16], concat_key[16];
	string swapped = "";
	for (int i = 0; i < 16; i++)
	{
		concat_key[i] = "";
	}
	key_rounds(original_key, concat_key);
	msg = IP(full_msg);
	l_msg = getStringLeft(msg); // left part of the message
	r_msg = getStringRight(msg); // right part of the message

	msg_left[0] = r_msg;
	msg_right[0] = XOR(l_msg, des_round(r_msg, concat_key[15]));

	msg_left[1] = msg_right[0];
	msg_right[1] = XOR(msg_left[0], des_round(msg_right[0], concat_key[14]));

	msg_left[2] = msg_right[1];
	msg_right[2] = XOR(msg_left[1], des_round(msg_right[1], concat_key[13]));

	msg_left[3] = msg_right[2];
	msg_right[3] = XOR(msg_left[2], des_round(msg_right[2], concat_key[12]));

	msg_left[4] = msg_right[3];
	msg_right[4] = XOR(msg_left[3], des_round(msg_right[3], concat_key[11]));

	msg_left[5] = msg_right[4];
	msg_right[5] = XOR(msg_left[4], des_round(msg_right[4], concat_key[10]));

	msg_left[6] = msg_right[5];
	msg_right[6] = XOR(msg_left[5], des_round(msg_right[5], concat_key[9]));

	msg_left[7] = msg_right[6];
	msg_right[7] = XOR(msg_left[6], des_round(msg_right[6], concat_key[8]));

	msg_left[8] = msg_right[7];
	msg_right[8] = XOR(msg_left[7], des_round(msg_right[7], concat_key[7]));

	msg_left[9] = msg_right[8];
	msg_right[9] = XOR(msg_left[8], des_round(msg_right[8], concat_key[6]));

	msg_left[10] = msg_right[9];
	msg_right[10] = XOR(msg_left[9], des_round(msg_right[9], concat_key[5]));

	msg_left[11] = msg_right[10];
	msg_right[11] = XOR(msg_left[10], des_round(msg_right[10], concat_key[4]));

	msg_left[12] = msg_right[11];
	msg_right[12] = XOR(msg_left[11], des_round(msg_right[11], concat_key[3]));

	msg_left[13] = msg_right[12];
	msg_right[13] = XOR(msg_left[12], des_round(msg_right[12], concat_key[2]));

	msg_left[14] = msg_right[13];
	msg_right[14] = XOR(msg_left[13], des_round(msg_right[13], concat_key[1]));

	msg_left[15] = msg_right[14];
	msg_right[15] = XOR(msg_left[14], des_round(msg_right[14], concat_key[0]));

	swapped = msg_right[15];
	swapped += msg_left[15];

	return b2hex(IP_1(swapped));
}
int main()
{
	string key, operation, text;
	char y_n;
	while (true)
	{
		cout << "Enter the operation (encrypt or decrypt):\n";
		cin >> operation;
		cout << "\n";
		cout << "Enter the 16-bit message -in the hexadecimal form- you want to encrypt/decrypt:\n";
		cin >> text;
		for (int i = 0; i < text.length(); i++)
		{
			if(isalpha(text[i]))
				text[i] = toupper(text[i]);
		}
		cout << "\n";
		cout << "Enter the 16-bit key -in the hexadecimal representation:\n";
		cin >> key;
		for (int i = 0; i < key.length(); i++)
		{
			if (isalpha(key[i]))
				key[i] = toupper(key[i]);
		}

		if (operation == "encrypt")
			cout << "cipher: " << encrypt(text, key) << "\n";
		else if (operation == "decrypt")
			cout << "plain: " << decrypt(text, key) << "\n";
		cout << "\n";
		cout << "Do you want to enter another message? [y/n]\n";
		cin >> y_n;
		if (y_n != 'y') break;
	}

	return 0;
}
