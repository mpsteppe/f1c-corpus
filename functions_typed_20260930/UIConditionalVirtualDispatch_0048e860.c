int __thiscall UIConditionalVirtualDispatch(_DWORD *this)
{
  int result; // eax

  result = this[58];
  if ( !result )
  {
    LinkedListTraversalWithVirtualCall((_DWORD *)this[16]);
    return (*(int (__thiscall **)(_DWORD *))(*this + 160))(this);
  }
  return result;
}

