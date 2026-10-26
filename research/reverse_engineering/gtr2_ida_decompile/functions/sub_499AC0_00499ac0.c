int __userpurge sub_499AC0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5)
{
  int result; // eax
  int v7; // ebp
  const char *v8; // esi
  int v9; // kr00_4
  char *i; // eax
  const char *v11; // eax
  unsigned int v12; // eax
  char *v13; // edi
  int v15; // eax
  int v16; // [esp+0h] [ebp-158h]
  int v17; // [esp+34h] [ebp-124h]
  int v18; // [esp+38h] [ebp-120h]
  int v19; // [esp+3Ch] [ebp-11Ch]
  char Buffer[15]; // [esp+48h] [ebp-110h] BYREF
  char v21; // [esp+57h] [ebp-101h] BYREF
  char v22[256]; // [esp+58h] [ebp-100h] BYREF

  sub_4D77F0();
  result = dword_BE1CD0;
  if ( dword_BE1CD0 > 0 )
  {
    v19 = a2;
    v18 = a4;
    v17 = a3;
    v7 = 0;
    do
    {
      v8 = (const char *)(dword_BE1CD8 + v7 + 4);
      strcpy(v22, v8);
      v9 = strlen(v22);
      if ( v9 > 0 )
      {
        for ( i = &v22[v9 - 1]; i >= v22; *i-- = 0 )
        {
          if ( *i == 92 )
            break;
        }
      }
      v11 = &v8[strlen(v8)];
      if ( v11 > v8 )
      {
        while ( *v11 != 92 )
        {
          if ( --v11 <= v8 )
            goto LABEL_12;
        }
        ++v11;
      }
LABEL_12:
      sprintf(Buffer, off_759F08, v11, v17, v18, v19);
      v12 = strlen(Buffer) + 1;
      v13 = &v21;
      while ( *++v13 )
        ;
      qmemcpy(v13, Buffer, v12);
      v15 = sub_4E0080(*(_DWORD *)(a1 + 48), v22, 0, 0, 1, 0, 0, 0, 0);
      if ( !v15 )
        v15 = sub_4E0080(*(_DWORD *)(a1 + 48), off_759F04[0], 0, 0, 1, 0, 0, 0, 0);
      sub_4D4B70(a1, v15);
      v7 += 396;
      result = --v16;
    }
    while ( v16 );
  }
  return result;
}
