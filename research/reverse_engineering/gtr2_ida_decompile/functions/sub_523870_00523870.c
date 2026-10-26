int __userpurge sub_523870@<eax>(int *a1@<ecx>, int a2@<edi>, float a3)
{
  int v3; // ecx
  int v4; // esi
  unsigned __int64 v5; // rax
  int v6; // esi
  int X_4; // [esp+4h] [ebp-14h]
  float v9; // [esp+Ch] [ebp-Ch]
  float v10; // [esp+10h] [ebp-8h]
  char v11; // [esp+14h] [ebp-4h]

  if ( a3 == -9.9999997e37 )
    a3 = *(float *)(*a1 + 2892852);
  v3 = *a1;
  v9 = *(float *)(v3 + 2892856);
  v11 = 1;
  v10 = a3;
  if ( a3 < (double)v9 )
  {
    v10 = *(float *)(v3 + 2892856);
    v9 = a3;
    v11 = 0;
  }
  sub_5231D0(v3, v9, v10, v11);
  sub_51C050((unsigned __int8 **)&dword_82F4A0);
  v4 = (unsigned __int64)floor(v9 * 40.0);
  v5 = (unsigned __int64)floor(v10 * 40.0);
  if ( v4 != (_DWORD)v5 )
  {
    LODWORD(v5) = sub_42DA10(&unk_920488);
    if ( dword_920480 < 105 )
    {
      X_4 = a2;
      do
      {
        v6 = 22616 * v5;
        sub_57CD10((char *)&unk_9204B0 + 22616 * v5, X_4);
        sub_56BD70((char *)&unk_920F30 + v6, LODWORD(a3));
        LODWORD(v5) = sub_42DA60(&unk_920488);
      }
      while ( dword_920480 < 105 );
    }
  }
  return v5;
}
