void __thiscall sub_5546A0(_DWORD *this, int *a2, int a3)
{
  *this = a3;
  sub_553FC0(this, a2[8]);
  sub_5542F0(this, a2[9]);
  SetterWithNotification(this, a2[10]);
  sub_554560(this, a2[12]);
  StateParameterSetterWithVirtualDeviceNotify(this, a2[11]);
  GameStateSettingViaVirtualDispatch(this, a2[13]);
  EnumToIDMappingWithVTableNotify(this, a2[14]);
}
