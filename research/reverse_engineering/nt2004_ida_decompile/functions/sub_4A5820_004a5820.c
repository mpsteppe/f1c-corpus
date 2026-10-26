void __thiscall sub_4A5820(_DWORD *this, char **a2, int a3)
{
  int v3; // esi
  int v4; // eax
  int v5; // [esp-10h] [ebp-18h]
  float v6; // [esp-Ch] [ebp-14h]

  v3 = this[15];
  if ( v3 )
  {
    v6 = *(float *)(v3 + 24);
    v5 = *(_DWORD *)(v3 + 20);
    v4 = sub_4AB570(&unk_765B00);
    sub_49CB80((char **)v3, 0, 0, v4, a2, a3, v5, v6, 0, 0);
  }
}
