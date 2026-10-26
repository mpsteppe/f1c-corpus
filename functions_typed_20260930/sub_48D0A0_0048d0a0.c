int __thiscall sub_48D0A0(int this)
{
  float v3; // [esp+0h] [ebp-8h]

  v3 = FloatFieldAccessor((float *)*(_DWORD *)(this + 64));
  CollisionPositionStepper((float *)this, v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)this + 172))(this);
  return 0;
}

