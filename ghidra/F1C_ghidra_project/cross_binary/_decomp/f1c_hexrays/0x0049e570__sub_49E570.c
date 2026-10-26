// f1c  0x0049e570  size=59
int __stdcall sub_49E570(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // edi
  int v10; // eax
  int result; // eax
  float v12; // [esp+0h] [ebp-18h]
  int i; // [esp+1Ch] [ebp+4h]

  if ( *(_DWORD *)(296 * a1 + dword_7C54E0 + 2100) && *(_BYTE *)(296 * a1 + dword_7C54E0 + 2164) )
  {
    if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
    {
      v5 = a5 / 3;
      v6 = 0;
      v7 = 1124 * a1;
      for ( i = 1124 * a1; ; v7 = i )
      {
        v8 = a3 + v6 * v5;
        v9 = v6 == 2 ? a3 + 2 * v5 + v5 : a5 + a3;
        v12 = *(double *)(v7 + 8 * v6 + 8157696) - 273.16;
        v10 = sub_49E5B0(v12);
        result = sub_543440(a2, v8, a4, v9 - v8, v10);
        if ( ++v6 >= 3 )
          break;
        v5 = a5 / 3;
      }
    }
    else
    {
      return sub_543440(a2, a3, a4, a5, -16711936);
    }
  }
  else
  {
    result = sub_587BDC(dbl_8AFEA0) % 2;
    if ( !result )
      return sub_543440(a2, a3, a4, a5, -65536);
  }
  return result;
}
