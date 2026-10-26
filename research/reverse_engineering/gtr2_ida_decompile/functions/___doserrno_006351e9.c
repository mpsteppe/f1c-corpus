unsigned int *__cdecl __doserrno()
{
  return (unsigned int *)(_getptd() + 12);
}
