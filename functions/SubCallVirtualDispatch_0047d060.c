int __thiscall SubCallVirtualDispatch(void *this)
{
  VehicleStatsEstimationDisplay(&byte_7C56C0);
  return (*(int (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
}
