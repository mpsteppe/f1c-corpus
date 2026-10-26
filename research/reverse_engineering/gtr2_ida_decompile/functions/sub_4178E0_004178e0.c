int __usercall sub_4178E0@<eax>(float *a1@<edx>, int a2@<ecx>, int a3@<edi>)
{
  int result; // eax
  int v5; // edx
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // ebp
  int i; // edi
  float *v10; // eax
  int v12; // [esp+4h] [ebp-Ch]
  int v13; // [esp+8h] [ebp-8h]
  int v14; // [esp+Ch] [ebp-4h]

  result = *(_DWORD *)(a2 + 544);
  v5 = 0;
  v13 = a2;
  v14 = result;
  v12 = 0;
  if ( result > 0 )
  {
    while ( 1 )
    {
      if ( v5 < 0 || v5 >= *(_DWORD *)(a2 + 544) )
        goto LABEL_10;
      v6 = *(_DWORD *)(a2 + 532);
      if ( v5 > 0 )
        break;
LABEL_9:
      if ( !v6 )
        goto LABEL_10;
      v7 = *(_DWORD **)v6;
LABEL_12:
      v8 = sub_5EA5B0(v7, a3);
      for ( i = 0; i < v8; v10[2] = v10[2] - a1[2] )
      {
        v10 = (float *)sub_5EB140(i++, 1);
        *v10 = *v10 - *a1;
        v10[1] = v10[1] - a1[1];
      }
      *v7 &= ~0x800u;
      sub_5EA6C0(1);
      a3 = 0;
      sub_5EAF10(v7);
      result = ++v12;
      if ( v12 >= v14 )
        return result;
      v5 = v12;
      a2 = v13;
    }
    while ( v6 )
    {
      v6 = *(_DWORD *)(v6 + 4);
      if ( --v5 <= 0 )
        goto LABEL_9;
    }
LABEL_10:
    v7 = 0;
    goto LABEL_12;
  }
  return result;
}
