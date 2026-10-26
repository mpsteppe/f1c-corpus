int __thiscall sub_59A3A9(int this, int a2, char a3)
{
  int result; // eax
  int v5; // eax

  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 40) = a2;
  *(_WORD *)(this + 48) = SingleByteWriteViaStream(32);
  result = StructFieldInitWithConditionalCall(this);
  if ( !*(_DWORD *)(this + 40) )
  {
    v5 = *(_DWORD *)(this + 4);
    LOBYTE(v5) = v5 | 4;
    result = sub_59A5FE(v5, 0);
  }
  if ( a3 )
    return sub_59A8FA(this);
  return result;
}

