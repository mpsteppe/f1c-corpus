int __thiscall StateMachineWithVirtualDispatch(_DWORD *this)
{
  switch ( ShortComputation_6720(this) )
  {
    case 1:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 6);
      (*(void (__thiscall **)(_DWORD *))(*this + 156))(this);
      return 0;
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 7);
      goto LABEL_6;
    case 4:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 8);
      (*(void (__thiscall **)(_DWORD *))(*this + 156))(this);
      return 0;
    case 5:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 9);
      goto LABEL_6;
    default:
LABEL_6:
      (*(void (__thiscall **)(_DWORD *))(*this + 156))(this);
      return 0;
  }
}

