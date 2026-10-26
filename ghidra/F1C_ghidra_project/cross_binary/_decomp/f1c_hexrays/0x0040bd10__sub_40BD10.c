// f1c  0x0040bd10  size=195
int __thiscall sub_40BD10(_DWORD *this, LPCSTR lpFileName, int a3)
{
  char v3; // bl
  int v6; // ebp
  int v7; // esi
  _DWORD v8[7]; // [esp+Ch] [ebp-1Ch] BYREF

  v3 = 0;
  if ( !lpFileName || !this[3] )
    return 1;
  sub_58BA36(lpFileName, 128);
  sub_5668B0(v8);
  if ( a3 )
    sub_566940(lpFileName, 0, 1, 1);
  else
    sub_566A70(lpFileName, 0, 1, 1);
  if ( !v8[0] )
    goto LABEL_7;
  v6 = 0;
  if ( (int)this[4] > 0 )
  {
    v3 = 1;
    v7 = 0;
    do
    {
      (*(void (__thiscall **)(int, _DWORD *, _DWORD))(*(_DWORD *)(this[3] + v7) + 8))(this[3] + v7, v8, 0);
      ++v6;
      v7 += 208;
    }
    while ( v6 < this[4] );
  }
  sub_566B90(v8);
  if ( !v3 )
  {
LABEL_7:
    sub_5668D0(v8);
    return 1;
  }
  sub_5668D0(v8);
  return 0;
}
