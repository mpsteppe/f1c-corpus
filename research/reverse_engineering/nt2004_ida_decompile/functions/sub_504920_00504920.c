char __stdcall sub_504920(int a1, int a2, int a3, float a4, float a5, float a6, float a7, int a8, int a9, char *a10)
{
  CHAR *v10; // eax
  int v11; // ebp
  CHAR *v12; // eax
  int v15; // edi
  int v16; // edi
  int v17; // ebp
  __int64 v18; // rax
  char result; // al
  char v20; // [esp+Fh] [ebp-9h]
  int v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h] BYREF
  int v23; // [esp+1Ch] [ebp+4h]
  int v24; // [esp+1Ch] [ebp+4h]
  int v25; // [esp+40h] [ebp+28h]
  int v26; // [esp+40h] [ebp+28h]

  v10 = *(CHAR **)dword_62A068;
  v11 = 0;
  v20 = 0;
  v22 = 0;
  if ( !*(_DWORD *)dword_62A068 )
    v10 = &byte_629120;
  sub_591F10(v10);
  sub_5924D0(dword_7DA988, (int)&v22, (int)aIngameMas);
  v12 = *(CHAR **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v12 = &byte_629120;
  sub_592030(v12);
  if ( v22 )
  {
    v15 = 0;
    v23 = 0;
    v21 = 0;
    v25 = sub_4B5EF0((char *)a1, a10);
    if ( v25 )
    {
      v23 = (__int64)(sub_501870() * (double)*(int *)(*(_DWORD *)(v25 + 16) + 28) * a4);
      v21 = (__int64)(sub_501880() * (double)*(int *)(*(_DWORD *)(v25 + 16) + 32) * a5);
      v15 = (__int64)(sub_501870() * (double)a2);
      v11 = (__int64)(sub_501880() * (double)a3);
      sub_4B5F70(a1, v15, v11, v23, v21, 2);
      v20 = 1;
    }
    v16 = v23 / 2 + v15;
    v17 = v21 / 2 + v11;
    v26 = sub_4B5F30((char *)a1, off_612BDC[0]);
    if ( v26 )
    {
      v24 = (__int64)(sub_501870() * (double)*(int *)(*(_DWORD *)(v26 + 16) + 28) * a6);
      v18 = (__int64)(sub_501880() * (double)*(int *)(*(_DWORD *)(v26 + 16) + 32) * a7);
      sub_4B60A0(a1, v16, v17, v24, v18, COERCE_FLOAT(2));
    }
    sub_592750(v22);
  }
  result = v20;
  *(_DWORD *)(a1 + 20) = a8;
  *(_DWORD *)(a1 + 24) = a9;
  return result;
}
