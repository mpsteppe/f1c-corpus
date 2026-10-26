void __thiscall sub_40B9B0(_DWORD *this, char a2)
{
  int v2; // edi
  const char *v4; // eax
  float v5; // [esp+8h] [ebp-24h] BYREF
  float v6; // [esp+Ch] [ebp-20h] BYREF
  float v7; // [esp+10h] [ebp-1Ch] BYREF
  _DWORD v8[3]; // [esp+14h] [ebp-18h] BYREF
  _BYTE v9[4]; // [esp+20h] [ebp-Ch] BYREF
  _BYTE v10[4]; // [esp+24h] [ebp-8h] BYREF
  _BYTE v11[4]; // [esp+28h] [ebp-4h] BYREF

  v2 = dword_7D6BB0;
  if ( dword_7D6BB0 && this[10] )
  {
    sub_593DA0(&v5, &v6, &v7, v9, v10, v11);
    v5 = v5 * -1.0;
    v6 = v6 * -1.0;
    v7 = v7 * -1.0;
    if ( a2 )
    {
      (*(void (__thiscall **)(int, float *, _BYTE *))(*(_DWORD *)v2 + 32))(v2, &v5, v9);
    }
    else
    {
      v4 = (const char *)sub_459BA0(this[4]);
      if ( _strcmpi(v4, aTrackside) )
      {
        v8[0] = *(_DWORD *)(dword_75AAC4 + 160);
        v8[1] = *(_DWORD *)(dword_75AAC4 + 164);
        v8[2] = *(_DWORD *)(dword_75AAC4 + 168);
      }
      else
      {
        sub_459BE0(v8);
      }
      (*(void (__thiscall **)(int, float *, _BYTE *, _DWORD *))(*(_DWORD *)v2 + 36))(v2, &v5, v9, v8);
    }
  }
}
