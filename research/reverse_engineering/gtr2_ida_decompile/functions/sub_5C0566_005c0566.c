// positive sp value has been detected, the output may be wrong!
float *__userpurge sub_5C0566@<eax>(char *a1@<ecx>, int a2, const void *a3)
{
  float *result; // eax
  float *v5; // edi
  float *v6; // esi
  int v7; // edi
  int i; // esi
  float v9[16]; // [esp-ACh] [ebp-BCh] BYREF
  float v10[16]; // [esp-6Ch] [ebp-7Ch] BYREF
  _BYTE v11[60]; // [esp-2Ch] [ebp-3Ch] BYREF

  result = (float *)*((_DWORD *)a1 + 97);
  if ( a3 )
  {
    qmemcpy(a1 + 68, a3, 0x40u);
    if ( !result )
    {
      v5 = (float *)(a1 + 4);
      v6 = (float *)(a1 + 68);
      goto LABEL_8;
    }
    qmemcpy(v9, result + 17, sizeof(v9));
    sub_5BE470(v9);
    qmemcpy(v10, v9, sizeof(v10));
    result = (float *)sub_42FBC0(a1 + 68, v11, v10);
    v5 = (float *)(a1 + 4);
  }
  else
  {
    if ( !result )
      return result;
    result = (float *)sub_42FBC0(a1 + 4, v11, result + 17);
    v5 = (float *)(a1 + 68);
  }
  v6 = result;
LABEL_8:
  qmemcpy(v5, v6, 0x40u);
  v7 = *((_DWORD *)a1 + 84);
  for ( i = 0; i < v7; ++i )
    result = (float *)sub_5C0560(*(void **)(*((_DWORD *)a1 + 86) + 4 * i), 0);
  return result;
}
