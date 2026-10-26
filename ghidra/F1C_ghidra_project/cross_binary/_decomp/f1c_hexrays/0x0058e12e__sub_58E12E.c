// f1c  0x0058e12e  size=127
int __cdecl sub_58E12E(int a1, int a2)
{
  int v2; // edi
  char v3; // bl
  int v4; // eax
  int result; // eax
  int v6; // ecx
  double v7; // st7
  _BYTE v8[12]; // [esp+Ch] [ebp-18h] BYREF
  double v9; // [esp+18h] [ebp-Ch] BYREF
  int v10; // [esp+20h] [ebp-4h] BYREF

  v2 = 0;
  v3 = sub_596245(v8, &v10, a2, 0, 0, 0, 0);
  if ( (v3 & 4) != 0 )
  {
    v2 = 512;
    v9 = 0.0;
  }
  else
  {
    v4 = sub_595524(v8, &v9);
    if ( (v3 & 2) != 0 || v4 == 1 )
      v2 = 128;
    if ( (v3 & 1) != 0 || v4 == 2 )
      v2 |= 0x100u;
  }
  result = a1;
  v6 = v10 - a2;
  v7 = v9;
  *(_DWORD *)a1 = v2;
  *(double *)(a1 + 16) = v7;
  *(_DWORD *)(a1 + 4) = v6;
  return result;
}
