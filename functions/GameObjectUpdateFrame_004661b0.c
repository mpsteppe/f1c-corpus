int __thiscall GameObjectUpdateFrame(int this)
{
  double v2; // st7

  if ( *(_DWORD *)(this + 232) )
    DoublyLinkedListAppend_6750(*(_DWORD *)(this + 64), this, 0);
  if ( *(float *)(this + 292) >= 0.0 )
  {
    v2 = *(float *)(this + 292) - FloatFieldAccessor((float *)*(_DWORD *)(this + 64));
    *(float *)(this + 292) = v2;
    if ( v2 < 0.0 )
    {
      FieldSetterCall(*(_DWORD **)(this + 64), 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)this + 172))(this);
    }
  }
  if ( *(_BYTE *)(this + 244) || *(_BYTE *)(this + 245) )
    sub_466350((float *)this);
  sub_466650((float *)this);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)this + 44))(this, 1);
  (*(void (__thiscall **)(int))(*(_DWORD *)this + 168))(this);
  return 0;
}
