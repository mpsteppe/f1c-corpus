Concurrency::details::VirtualProcessor *__thiscall sub_4AC170(_DWORD *this, int *a2, int *a3)
{
  int v3; // edx
  int v4; // ebp
  Concurrency::details::VirtualProcessor *v5; // edi
  Concurrency::details::VirtualProcessor *i; // esi
  int v7; // ebp
  Concurrency::details::VirtualProcessor *j; // esi
  int v10; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h]

  v11 = this[22];
  v10 = this[23];
  v4 = sub_4AC160(this);
  v12 = v4;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = 0;
  if ( !v4 )
    return (Concurrency::details::VirtualProcessor *)v3;
  v5 = 0;
  for ( i = (Concurrency::details::VirtualProcessor *)sub_4AF0A0(v4);
        i;
        i = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(i) )
  {
    if ( (*(int (__thiscall **)(Concurrency::details::VirtualProcessor *, int, int))(*(_DWORD *)i + 20))(i, v11, v10) )
    {
      v5 = i;
      if ( a2 )
        *a2 = v4;
    }
  }
  if ( sub_4AEF90(v4) && !v5 )
  {
    v7 = sub_4AEF90(v4);
    if ( sub_4AF450(v7) )
      v7 = sub_4AF450(v7);
    for ( j = *(Concurrency::details::VirtualProcessor **)(v7 + 52);
          j;
          j = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(j) )
    {
      if ( (*(int (__thiscall **)(Concurrency::details::VirtualProcessor *, int, int))(*(_DWORD *)j + 20))(j, v11, v10) )
        v5 = j;
    }
    if ( a2 )
      *a2 = v12;
    if ( a3 )
      *a3 = v7;
  }
  return v5;
}
