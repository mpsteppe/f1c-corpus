char __stdcall sub_53A7E0(int *a1, int *a2, float *a3, char *String1)
{
  char *v4; // eax
  int v6; // ebp
  int v7; // edi
  char v8; // bl
  _DWORD *v9; // eax
  char *v10; // eax
  _DWORD *v11; // eax
  char *v12; // eax
  _DWORD *v13; // eax
  char *v14; // eax
  double v15; // st7

  v4 = String1;
  if ( !String1 )
    v4 = (char *)(396 * dword_BE1CD4 + dword_BE1CD8 + 260);
  if ( !sub_53A250(v4) )
    return 1;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = (_DWORD *)sub_616630("UnlockGold");
  if ( v9 )
  {
    v10 = sub_48D380(v9);
    v7 = atol(v10);
  }
  v11 = (_DWORD *)sub_616630("UnlockPass");
  if ( v11 )
  {
    v12 = sub_48D380(v11);
    v6 = atol(v12);
  }
  v13 = (_DWORD *)sub_616630("UnlockPoints");
  if ( v13 )
  {
    v14 = sub_48D380(v13);
    v15 = atof(v14);
  }
  else
  {
    v15 = 0.0;
  }
  if ( dword_B76230 < v7 || *(int *)ArgList < v6 || flt_B76228 < v15 )
    v8 = 1;
  if ( a1 )
    *a1 = v7;
  if ( a2 )
    *a2 = v6;
  if ( !a3 )
    return v8;
  *a3 = v15;
  return v8;
}
