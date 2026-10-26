int __thiscall sub_587120(_DWORD *this, void **a2, int *a3)
{
  signed int *v3; // ebx
  int v4; // edi
  signed int v5; // eax
  int result; // eax
  const void *v7; // [esp+10h] [ebp-4h] BYREF

  v3 = a3;
  v4 = *a3;
  if ( FieldAccessor(this + 1) > v4 )
    goto LABEL_8;
  v7 = 0;
  a3 = (int *)v4;
  if ( !(unsigned __int8)BufferQueryReturnPtrSizeIfValid(&v7, &a3) )
    goto LABEL_8;
  v5 = *v3;
  if ( (int)a3 < *v3 )
    v5 = (signed int)a3;
  if ( v5 > 0 && *a2 )
  {
    qmemcpy(*a2, v7, v5);
    *v3 = v5;
    return 0;
  }
  else
  {
LABEL_8:
    *a2 = 0;
    result = 1;
    *v3 = 0;
  }
  return result;
}
