char __thiscall sub_4B5040(_BYTE *this, unsigned __int8 a2)
{
  FileWriteWithBackendDispatch(this, 1);
  FileWriteWithBackendDispatch(&a2, 1);
  FileWriteWithBackendDispatch(this + 1, a2);
  this[a2 + 1] = 0;
  FileWriteWithBackendDispatch(this + 65, 32);
  FileWriteWithBackendDispatch(this + 97, 32);
  FileWriteWithBackendDispatch(this + 132, 4);
  FileWriteWithBackendDispatch(this + 136, 4);
  return 1;
}

