int __thiscall sub_4AF650(_DWORD *this, char a2)
{
  _DWORD *i; // esi
  int v3; // eax
  int v5; // ecx
  Concurrency::details::VirtualProcessor *j; // esi
  int v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-8h] [ebp-Ch]

  for ( i = this; sub_4AF450(i); i = (_DWORD *)sub_4AF450(i) )
    ;
  if ( i[15] )
  {
    v5 = i[16];
    if ( v5 && a2 )
      sub_4B03B0(v5);
    for ( j = (Concurrency::details::VirtualProcessor *)i[13];
          j;
          j = (Concurrency::details::VirtualProcessor *)Concurrency::details::VirtualProcessor::GetExecutionResourceId(j) )
    {
      (*(void (__thiscall **)(Concurrency::details::VirtualProcessor *))(*(_DWORD *)j + 48))(j);
    }
    return 0;
  }
  else
  {
    v8 = dword_6152EC;
    v7 = dword_6152E8;
    v3 = sub_4AB570();
    sub_4AB0E0(v3, 0, 0, v7, v8, 16);
    return -1;
  }
}
