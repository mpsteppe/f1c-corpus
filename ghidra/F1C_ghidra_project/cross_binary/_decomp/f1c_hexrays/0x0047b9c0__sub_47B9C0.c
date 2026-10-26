// f1c  0x0047b9c0  size=281
int __thiscall sub_47B9C0(int this, int a2)
{
  const char **v3; // eax
  const char *v4; // ebx
  unsigned int v5; // kr04_4
  int v6; // edi
  int i; // ebp
  int v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  char v12; // cl
  int v13; // ebx
  int result; // eax
  char v15; // [esp+13h] [ebp-11h]
  char *v16; // [esp+14h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v18[4]; // [esp+20h] [ebp-4h] BYREF

  v3 = *(const char ***)(this + 224);
  v4 = *v3;
  if ( *v3 )
  {
    v16 = (char *)*v3;
  }
  else
  {
    v16 = byte_5EA438;
    v4 = byte_5EA438;
  }
  v5 = strlen(v4) + 1;
  v6 = 0;
  for ( i = 0; ; ++i )
  {
    v8 = sub_47B730(this, v6);
    if ( v6 == v8 || *(_DWORD *)(this + 228) < v8 || v5 - 1 == v8 && v4[v8 - 1] != -1 )
      break;
    v6 = v8;
  }
  v9 = *(_DWORD *)(this + 200);
  if ( v9 )
  {
    v10 = *(char **)(v9 + 64);
    if ( !v10 )
      v10 = byte_5EA438;
    sub_498560(v10);
  }
  v11 = *(_DWORD *)(this + 228);
  v12 = v4[v11];
  v4[v11] = 0;
  v15 = v12;
  sub_4983B0(&v4[v6], &v17, v18, 1);
  v4[*(_DWORD *)(this + 228)] = v15;
  v13 = a2 + i;
  if ( a2 + i < 0 )
    v13 = 0;
  if ( v13 < i )
  {
    i = 0;
    v6 = 0;
    sub_47B730(this, 0);
  }
  while ( 1 )
  {
    result = sub_47B730(this, v6);
    if ( i >= v13 )
      break;
    if ( !v16[result] )
      goto LABEL_22;
    ++i;
    v6 = result;
  }
  result = sub_47B910((_DWORD **)this, v17, v6, result);
LABEL_22:
  *(_DWORD *)(this + 228) = result;
  return result;
}
