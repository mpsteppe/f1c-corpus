int __thiscall sub_4A6450(_DWORD *this)
{
  float *v1; // eax
  double v2; // st7
  char Buffer; // [esp+Ch] [ebp-20h] BYREF
  int v5; // [esp+Dh] [ebp-1Fh]
  int v6; // [esp+11h] [ebp-1Bh]
  int v7; // [esp+15h] [ebp-17h]
  int v8; // [esp+19h] [ebp-13h]
  int v9; // [esp+1Dh] [ebp-Fh]
  int v10; // [esp+21h] [ebp-Bh]
  int v11; // [esp+25h] [ebp-7h]
  __int16 v12; // [esp+29h] [ebp-3h]
  char v13; // [esp+2Bh] [ebp-1h]

  v1 = (float *)((char *)&unk_9204A0 + 22616 * this[210]);
  if ( !v1 || *(_DWORD *)dword_B640C8 == 6 )
    return (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 40))(this, 0);
  v2 = v1[4021];
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  Buffer = 0;
  v13 = 0;
  if ( dword_B72454 )
    sprintf(&Buffer, "%.0flbs", v2 * 2.2);
  else
    sprintf(&Buffer, "%.0fkg", v2);
  return sub_4CE770(&Buffer);
}
