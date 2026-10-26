void __thiscall sub_4A4C90(int this, int a2, char **a3, int a4)
{
  int v4; // eax
  int v5; // [esp-10h] [ebp-18h]
  float v6; // [esp-Ch] [ebp-14h]

  if ( *(_BYTE *)(this + 432) && a2 && *(_BYTE *)(this + 428) )
  {
    if ( *(_DWORD *)(this + 272) )
    {
      v6 = *(float *)(a2 + 24);
      v5 = *(_DWORD *)(a2 + 20);
      v4 = sub_4AB570(&unk_765B00);
      sub_49CB80((char **)a2, 0, 0, v4, a3, a4, v5, v6, 0, 0);
    }
  }
}
