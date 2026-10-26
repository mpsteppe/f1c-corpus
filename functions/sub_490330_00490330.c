int __thiscall sub_490330(_DWORD *this)
{
  switch ( ShortComputation_6720(this) )
  {
    case 0:
    case 1:
    case 2:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 2);
      break;
    case 3:
    case 4:
    case 5:
      (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 5);
      break;
    default:
      break;
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  VTableDispatchListIteration(this);
  return 0;
}
