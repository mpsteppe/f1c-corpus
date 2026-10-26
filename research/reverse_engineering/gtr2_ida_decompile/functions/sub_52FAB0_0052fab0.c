// positive sp value has been detected, the output may be wrong!
char __userpurge sub_52FAB0@<al>(float *a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4)
{
  int v4; // ebp
  unsigned __int64 v5; // rax
  int v6; // edi
  unsigned __int64 v7; // rax
  int v8; // esi
  unsigned __int64 v9; // rax
  int v10; // ebx
  unsigned __int64 v11; // rax
  int v12; // ecx
  float *v13; // edi
  int v14; // esi
  bool v15; // zf
  char result; // al
  int v17; // [esp-10h] [ebp-28h]
  float *v19; // [esp+4h] [ebp-14h]
  float *v20; // [esp+8h] [ebp-10h]
  int v21; // [esp+10h] [ebp-8h]
  float *v22; // [esp+14h] [ebp-4h]
  int v23; // [esp+14h] [ebp-4h]
  int retaddr; // [esp+18h] [ebp+0h]

  v4 = (int)v22;
  v17 = a2;
  v20 = a1;
  v5 = (unsigned __int64)((v22[4] - v22[7] - a1[585]) * a1[586]);
  v6 = v5;
  if ( (v5 & 0x80000000) == 0LL )
  {
    if ( (int)v5 >= 8 )
      v6 = 7;
  }
  else
  {
    v6 = 0;
  }
  v7 = (unsigned __int64)((v22[7] + v22[4] - a1[585]) * a1[586]);
  v8 = v7;
  if ( (v7 & 0x80000000) == 0LL )
  {
    if ( (int)v7 >= 8 )
      v8 = 7;
  }
  else
  {
    v8 = 0;
  }
  v9 = (unsigned __int64)((v22[6] - v22[7] - a1[587]) * a1[588]);
  v10 = v9;
  if ( (v9 & 0x80000000) == 0LL )
  {
    if ( (int)v9 >= 8 )
      v10 = 7;
  }
  else
  {
    v10 = 0;
  }
  v11 = (unsigned __int64)((v22[6] + v22[7] - a1[587]) * a1[588]);
  v12 = v11;
  if ( (v11 & 0x80000000) == 0LL )
  {
    if ( (int)v11 < 8 )
      goto LABEL_18;
    v23 = 7;
  }
  else
  {
    v23 = 0;
  }
  v12 = v23;
LABEL_18:
  if ( v6 <= v8 )
  {
    v19 = &v20[72 * v6 + 9 * v10];
    do
    {
      if ( v10 <= v12 )
      {
        v13 = v19;
        v14 = v12 - v10 + 1;
        do
        {
          sub_52F280(v4, v17);
          v13 += 9;
          --v14;
        }
        while ( v14 );
        v12 = retaddr;
      }
      v15 = v21 == 1;
      v20 += 72;
      --v21;
    }
    while ( !v15 );
  }
  result = HIBYTE(v19);
  if ( HIBYTE(v19) )
    return sub_52F280(v4, a3);
  return result;
}
