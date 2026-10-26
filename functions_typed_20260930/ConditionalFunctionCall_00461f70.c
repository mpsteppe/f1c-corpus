int __thiscall ConditionalFunctionCall(int *this)
{
  int result; // eax
  int v2; // ecx

  result = *this;
  v2 = *(_DWORD *)(*this + 112540);
  if ( v2 )
    return sub_563410(v2);
  return result;
}

