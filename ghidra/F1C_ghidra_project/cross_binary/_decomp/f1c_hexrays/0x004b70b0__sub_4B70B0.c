// f1c  0x004b70b0  size=290
int __thiscall sub_4B70B0(_DWORD *this)
{
  int v2; // esi
  int v3; // ebx
  int v4; // edi
  char *v5; // eax
  int v7; // [esp+10h] [ebp-Ch]
  float v8; // [esp+14h] [ebp-8h] BYREF
  _BYTE v9[4]; // [esp+18h] [ebp-4h] BYREF

  sub_4B87A0(&v8, v9);
  v2 = 0;
  v3 = 0;
  v7 = 0;
  do
  {
    v4 = sub_4B72A0(v7, v8);
    if ( v4 )
    {
      sub_4EF5A0(3, 0);
      sub_4C7B20(v4 + 65);
      sub_566650(v4 + 97);
      sub_4C6980(v4 + 1);
      ++v3;
    }
    else
    {
      sub_4EF5A0(-1, 0);
    }
    v2 += 18624;
    ++v7;
  }
  while ( v2 < 1936896 );
  dword_5C329C = v3 - 1;
  sub_42BC80();
  dword_7CEC90 = 0;
  dword_7CED8C = 0;
  dword_7CEE88 = 0;
  dword_7D0990 = (v3 - 1) & ((v3 - 1 < 0) - 1);
  v5 = (char *)this[457];
  if ( !v5 )
    v5 = byte_5EA438;
  sub_4C5690(v5);
  sub_4C54F0(0);
  byte_7C5690 = 1;
  return sub_42CF10(&dword_7C569C, this[968]);
}
