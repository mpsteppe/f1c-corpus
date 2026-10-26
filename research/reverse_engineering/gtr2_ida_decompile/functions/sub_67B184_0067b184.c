int __stdcall sub_67B184(int *a1, void **a2, int *a3)
{
  int result; // eax
  void *v4; // esi
  void *Block; // [esp+Ch] [ebp-8h]
  void *v6; // [esp+10h] [ebp-4h]

  result = (int)a1;
  v4 = 0;
  v6 = 0;
  Block = 0;
  if ( a1 )
  {
    result = *a1;
    v6 = (void *)*a1;
  }
  if ( a2 )
    v4 = *a2;
  if ( a3 )
  {
    result = *a3;
    Block = (void *)*a3;
  }
  if ( v6 )
    result = sub_67B06D((int)v6, v4, Block);
  if ( v4 )
  {
    result = sub_6B7251(v4);
    *a2 = 0;
  }
  if ( Block )
  {
    result = sub_6B7251(Block);
    *a3 = 0;
  }
  if ( v6 )
  {
    sub_6B7251(v6);
    result = (int)a1;
    *a1 = 0;
  }
  return result;
}
