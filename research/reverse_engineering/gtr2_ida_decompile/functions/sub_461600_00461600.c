int __thiscall sub_461600(char *this)
{
  int result; // eax
  char *v2; // ecx
  int v3; // esi

  result = 0;
  byte_B69909 = 2;
  byte_B69989 = 2;
  byte_B69924 = 2;
  byte_B69916 = 2;
  byte_B69922 = 2;
  byte_B699BE = 0;
  byte_B699B3 = 0;
  byte_B699B5 = 0;
  byte_B699BF = 0;
  byte_B699BB = 0;
  byte_B699BD = 0;
  byte_B698F9 = 1;
  byte_B698F8 = 1;
  byte_B699B1 = 0;
  byte_B69925 = 0;
  byte_B69936 = 0;
  byte_B6993A = 0;
  byte_B699A1 = 2;
  byte_B69923 = 2;
  byte_B69906 = 2;
  byte_B69907 = 2;
  byte_B698EE = 0;
  byte_B698EF = 0;
  byte_B698F0 = 0;
  byte_B698F1 = 0;
  byte_B698F2 = 0;
  byte_B698F3 = 0;
  byte_B698F4 = 0;
  byte_B698F5 = 0;
  byte_B698F6 = 0;
  byte_B698F7 = 0;
  byte_B6993B = 2;
  byte_B6993C = 2;
  byte_B6993D = 2;
  byte_B69937 = 2;
  byte_B69938 = 2;
  byte_B69939 = 2;
  byte_B69933 = 2;
  byte_B69934 = 2;
  byte_B69935 = 2;
  byte_B69927 = 0;
  byte_B69928 = 0;
  byte_B69929 = 0;
  byte_B6992A = 0;
  byte_B6992B = 0;
  byte_B6992C = 0;
  byte_B6992D = 0;
  byte_B6992E = 0;
  byte_B6992F = 0;
  byte_B69930 = 0;
  byte_B69943 = 0;
  byte_B69944 = 0;
  byte_B698FA = 2;
  byte_B699B4 = 2;
  byte_B699BC = 2;
  byte_B699B7 = 2;
  byte_B699B9 = 2;
  v2 = this + 8080;
  v3 = 17;
  do
  {
    if ( !*((_DWORD *)v2 - 1) )
      byte_B698EC[*(_DWORD *)v2] = v2[4];
    if ( !*((_DWORD *)v2 + 10) )
      byte_B698EC[*((_DWORD *)v2 + 11)] = v2[48];
    if ( !*((_DWORD *)v2 + 21) )
      byte_B698EC[*((_DWORD *)v2 + 22)] = v2[92];
    if ( !*((_DWORD *)v2 + 32) )
      byte_B698EC[*((_DWORD *)v2 + 33)] = v2[136];
    v2 += 176;
    --v3;
  }
  while ( v3 );
  return result;
}
