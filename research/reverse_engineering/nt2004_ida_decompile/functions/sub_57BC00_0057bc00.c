int __thiscall sub_57BC00(int this, const char *a2, double a3, const void *a4)
{
  char *v5; // eax

  v5 = (char *)operator new(strlen(a2) + 1);
  *(_DWORD *)this = v5;
  strcpy(v5, a2);
  *(double *)(this + 172) = a3;
  *(double *)(this + 180) = 1.0 / a3;
  qmemcpy((void *)(this + 188), a4, 0x18u);
  *(double *)(this + 212) = 1.0 / *(double *)(this + 188);
  *(double *)(this + 220) = 1.0 / *(double *)(this + 196);
  *(double *)(this + 228) = 1.0 / *(double *)(this + 204);
  return sub_57C1A0(this);
}
