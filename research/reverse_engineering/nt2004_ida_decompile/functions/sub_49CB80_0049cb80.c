void __stdcall sub_49CB80(char **a1, int a2, int a3, int a4, char **a5, int a6, int a7, float a8, int a9, int a10)
{
  char **v10; // edi
  char *v11; // eax
  int v12; // esi
  char *v13; // edi
  int v14; // [esp+Ch] [ebp-8h] BYREF
  int v15; // [esp+10h] [ebp-4h] BYREF

  v10 = a1;
  if ( a1 && a4 )
  {
    v11 = *a1;
    if ( !*a1 )
      v11 = &byte_629120;
    v12 = sub_49CF00(v11);
    if ( v12 )
      goto LABEL_20;
    sub_49CD60(v10, 1);
    v13 = *v10;
    if ( !v13 )
      v13 = &byte_629120;
    v12 = sub_49CF00(v13);
    if ( v12 )
    {
LABEL_20:
      if ( (unsigned __int8)sub_4B04D0(&a1, &a4) && (unsigned __int8)sub_4B0560(&v14, &v15) )
      {
        if ( a1 != a5 || a4 != a6 )
          sub_4AFF20(a5, a6);
        if ( v14 != a7 || v15 != LODWORD(a8) )
          sub_4B0090(a7, a8);
        sub_4B03B0(v12);
      }
    }
  }
}
