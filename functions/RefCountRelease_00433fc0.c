int __thiscall RefCountRelease(void *this, const char *a2, char a3)
{
  int v3; // esi

  v3 = 1;
  if ( !VehicleSetupFileWriter(&byte_7C56C0, (int)a2, 1) )
  {
    v3 = 0;
    if ( a3 )
      StringCopyWithBufferRealloc((int)this + 8, a2);
  }
  return v3;
}
