void __thiscall sub_51D5A0(float *this)
{
  unsigned __int8 v3; // c0
  unsigned __int8 v4; // c2
  float v5; // [esp+4h] [ebp-34h]
  int v6; // [esp+8h] [ebp-30h] BYREF
  float v7; // [esp+14h] [ebp-24h] BYREF
  _DWORD v8[3]; // [esp+20h] [ebp-18h] BYREF
  _DWORD v9[3]; // [esp+2Ch] [ebp-Ch] BYREF

  v5 = 1.0;
  if ( *((_DWORD *)this + 1) != *(_DWORD *)(LODWORD(dword_75AAD0[dword_75AAC0]) + 25248) )
  {
    sub_4F8F50(*(_DWORD **)this, &v6, v8);
    sub_51C1E0(this, &v7, v9);
    if ( v3 | v4 )
      v5 = *(float *)&dword_767C34;
  }
  sub_50E010((int)(this + 452), v5);
}
