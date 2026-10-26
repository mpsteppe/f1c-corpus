int __thiscall sub_4B2EE0(float *this)
{
  _DWORD *v2; // edi
  _DWORD *v3; // eax
  char *v4; // eax
  _DWORD *v5; // eax
  char *v6; // eax
  double v7; // st7
  unsigned __int64 v8; // rax
  int v9; // ecx
  int v11; // [esp+8h] [ebp-48h]
  char Buffer[61]; // [esp+10h] [ebp-40h] BYREF
  __int16 v13; // [esp+4Dh] [ebp-3h]
  char v14; // [esp+4Fh] [ebp-1h]

  memset(Buffer, 0, sizeof(Buffer));
  v13 = 0;
  v14 = 0;
  v2 = (_DWORD *)(*(int (__thiscall **)(float *))(*(_DWORD *)this + 188))(this);
  v11 = 0;
  this[73] = (float)dword_B71DF4;
  v3 = (_DWORD *)sub_501730(&byte_B6F530, "Damage");
  if ( v3 )
  {
    v4 = sub_48D380(v3);
    this[73] = (float)atol(v4);
  }
  v5 = (_DWORD *)sub_616840("Damage");
  if ( v5 )
  {
    v6 = sub_48D380(v5);
    v11 = atol(v6);
  }
  v7 = (double)v11;
  if ( v7 > this[73] )
    this[73] = v7;
  if ( (double)dword_B71DEC < this[73] )
  {
    v8 = (unsigned __int64)this[73];
    v9 = dword_B71DF4;
    dword_B71DEC = v8;
    if ( (int)v8 < dword_B71DF4 || (v9 = dword_B71DF8, (int)v8 > dword_B71DF8) )
      dword_B71DEC = v9;
  }
  if ( v2 )
    sprintf(Buffer, "%d%%", *v2);
  sub_615860(Buffer);
  return 0;
}
