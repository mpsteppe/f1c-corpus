int __thiscall sub_585380(_DWORD *this, int a2)
{
  int v3; // edi

  v3 = 2;
  if ( a2 )
  {
    ThreadSafeCallWithMutex(this, a2);
    v3 = 0;
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 56))(this);
  return v3;
}

