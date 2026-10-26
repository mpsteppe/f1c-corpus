void __stdcall sub_567A90(_DWORD *a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax

  if ( a1 )
  {
    v1 = sub_5679A0(0);
    while ( v1 )
    {
      v2 = v1;
      v1 = *(_DWORD *)(v1 + 4);
      sub_567A90(v2);
    }
    v3 = sub_49ADB0(a1);
    if ( v3 )
      sub_567A90(v3);
    sub_567940((int)a1);
    sub_587BCF(a1);
  }
}
