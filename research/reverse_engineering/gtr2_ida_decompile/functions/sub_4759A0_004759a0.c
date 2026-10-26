char __thiscall sub_4759A0(int *this, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  unsigned int v7; // ebp
  int v8; // ebx
  int v9; // eax
  int v11; // esi
  float v12; // [esp+0h] [ebp-228h]
  int v13; // [esp+14h] [ebp-214h] BYREF
  _BYTE v14[4]; // [esp+18h] [ebp-210h] BYREF
  int v15; // [esp+1Ch] [ebp-20Ch]
  char v16; // [esp+218h] [ebp-10h]

  sub_4733E0(v14);
  sub_59B5C0(v14, 528, &v13);
  v4 = *(&dword_91E088 + v16);
  v5 = *this;
  v6 = *(_DWORD *)(*this + 112884);
  v7 = 0;
  v13 = v4;
  if ( v6 )
  {
    v8 = 0;
    do
    {
      if ( v7 != (unsigned __int8)sub_59B590(*(_DWORD *)(v5 + 113316)) )
      {
        v9 = strcmp((const char *)(v8 + *this + 2236), (const char *)(108 * a3 + v4 + 21568));
        v4 = v13;
        if ( !v9 )
          break;
      }
      v5 = *this;
      ++v7;
      v8 += 528;
    }
    while ( v7 < *(_DWORD *)(*this + 112884) );
  }
  if ( v7 == *(_DWORD *)(*this + 112884) )
    return 0;
  v15 = 2;
  if ( !sub_59B5A0(v14, 528) )
    sub_42CB90();
  *(_DWORD *)(v4 + 21788) = a3;
  sub_4FBED0(a3);
  sub_423790();
  v11 = off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  v12 = dbl_FB1D18;
  sub_51B2A0(4, 49, 4, v16, LODWORD(v12), 3);
  *(_WORD *)(v11 + 8) = a3;
  *(_WORD *)(v11 + 10) = v7;
  return 1;
}
