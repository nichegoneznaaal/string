#include "s21_string.h"

#define OUT_ERROR "Unknown error: %d"

#if defined(__linux__)
#define SUM_ERRORS 134
char *errors[] = {"Success",
                  "Operation not permitted",
                  "No such file or directory",
                  "No such process",
                  "Interrupted system call",
                  "Input/output error",
                  "No such device or address",
                  "Argument list too long",
                  "Exec format error",
                  "Bad file descriptor",
                  "No child processes",
                  "Resource temporarily unavailable",
                  "Cannot allocate memory",
                  "Permission denied",
                  "Bad address",
                  "Block device required",
                  "Device or resource busy",
                  "File exists",
                  "Invalid cross-device link",
                  "No such device",
                  "Not a directory",
                  "Is a directory",
                  "Invalid argument",
                  "Too many open files in system",
                  "Too many open files",
                  "Inappropriate ioctl for device",
                  "Text file busy",
                  "File too large",
                  "No space left on device",
                  "Illegal seek",
                  "Read-only file system",
                  "Too many links",
                  "Broken pipe",
                  "Numerical argument out of domain",
                  "Numerical result out of range",
                  "Resource deadlock avoided",
                  "File name too long",
                  "No locks available",
                  "Function not implemented",
                  "Directory not empty",
                  "Too many levels of symbolic links",
                  "Unknown error 41",
                  "No message of desired type",
                  "Identifier removed",
                  "Channel number out of range",
                  "Level 2 not synchronized",
                  "Level 3 halted",
                  "Level 3 reset",
                  "Link number out of range",
                  "Protocol driver not attached",
                  "No CSI structure available",
                  "Level 2 halted",
                  "Invalid exchange",
                  "Invalid request descriptor",
                  "Exchange full",
                  "No anode",
                  "Invalid request code",
                  "Invalid slot",
                  "Unknown error 58",
                  "Bad font file format",
                  "Device not a stream",
                  "No data available",
                  "Timer expired",
                  "Out of streams resources",
                  "Machine is not on the network",
                  "Package not installed",
                  "Object is remote",
                  "Link has been severed",
                  "Advertise error",
                  "Srmount error",
                  "Communication error on send",
                  "Protocol error",
                  "Multihop attempted",
                  "RFS specific error",
                  "Bad message",
                  "Value too large for defined data type",
                  "Name not unique on network",
                  "File descriptor in bad state",
                  "Remote address changed",
                  "Can not access a needed shared library",
                  "Accessing a corrupted shared library",
                  ".lib section in a.out corrupted",
                  "Attempting to link in too many shared libraries",
                  "Cannot exec a shared library directly",
                  "Invalid or incomplete multibyte or wide character",
                  "Interrupted system call should be restarted",
                  "Streams pipe error",
                  "Too many users",
                  "Socket operation on non-socket",
                  "Destination address required",
                  "Message too long",
                  "Protocol wrong type for socket",
                  "Protocol not available",
                  "Protocol not supported",
                  "Socket type not supported",
                  "Operation not supported",
                  "Protocol family not supported",
                  "Address family not supported by protocol",
                  "Address already in use",
                  "Cannot assign requested address",
                  "Network is down",
                  "Network is unreachable",
                  "Network dropped connection on reset",
                  "Software caused connection abort",
                  "Connection reset by peer",
                  "No buffer space available",
                  "Transport endpoint is already connected",
                  "Transport endpoint is not connected",
                  "Cannot send after transport endpoint shutdown",
                  "Too many references: cannot splice",
                  "Connection timed out",
                  "Connection refused",
                  "Host is down",
                  "No route to host",
                  "Operation already in progress",
                  "Operation now in progress",
                  "Stale file handle",
                  "Structure needs cleaning",
                  "Not a XENIX named type file",
                  "No XENIX semaphores available",
                  "Is a named type file",
                  "Remote I/O error",
                  "Disk quota exceeded",
                  "No medium found",
                  "Wrong medium type",
                  "Operation canceled",
                  "Required key not available",
                  "Key has expired",
                  "Key has been revoked",
                  "Key was rejected by service",
                  "Owner died",
                  "State not recoverable",
                  "Operation not possible due to RF-kill",
                  "Memory page has hardware error"};

#elif defined(__APPLE__)
#define SUM_ERRORS 107
char *errors[] = {"Undefined error: 0",
                  "Operation not permitted",
                  "No such file or directory",
                  "No such process",
                  "Interrupted system call",
                  "Input/output error",
                  "Device not configured",
                  "Argument list too long",
                  "Exec format error",
                  "Bad file descriptor",
                  "No child processes",
                  "Resource deadlock avoided",
                  "Cannot allocate memory",
                  "Permission denied",
                  "Bad address",
                  "Block device required",
                  "Resource busy",
                  "File exists",
                  "Cross-device link",
                  "Operation not supported by device",
                  "Not a directory",
                  "Is a directory",
                  "Invalid argument",
                  "Too many open files in system",
                  "Too many open files",
                  "Inappropriate ioctl for device",
                  "Text file busy",
                  "File too large",
                  "No space left on device",
                  "Illegal seek",
                  "Read-only file system",
                  "Too many links",
                  "Broken pipe",
                  "Numerical argument out of domain",
                  "Result too large",
                  "Resource temporarily unavailable",
                  "Operation now in progress",
                  "Operation already in progress",
                  "Socket operation on non-socket",
                  "Destination address required",
                  "Message too long",
                  "Protocol wrong type for socket",
                  "Protocol not available",
                  "Protocol not supported",
                  "Socket type not supported",
                  "Operation not supported",
                  "Protocol family not supported",
                  "Address family not supported by protocol family",
                  "Address already in use",
                  "Can't assign requested address",
                  "Network is down",
                  "Network is unreachable",
                  "Network dropped connection on reset",
                  "Software caused connection abort",
                  "Connection reset by peer",
                  "No buffer space available",
                  "Socket is already connected",
                  "Socket is not connected",
                  "Can't send after socket shutdown",
                  "Too many references: can't splice",
                  "Operation timed out",
                  "Connection refused",
                  "Too many levels of symbolic links",
                  "File name too long",
                  "Host is down",
                  "No route to host",
                  "Directory not empty",
                  "Too many processes",
                  "Too many users",
                  "Disc quota exceeded",
                  "Stale NFS file handle",
                  "Too many levels of remote in path",
                  "RPC struct is bad",
                  "RPC version wrong",
                  "RPC prog. not avail",
                  "Program version wrong",
                  "Bad procedure for program",
                  "No locks available",
                  "Function not implemented",
                  "Inappropriate file type or format",
                  "Authentication error",
                  "Need authenticator",
                  "Device power is off",
                  "Device error",
                  "Value too large to be stored in data type",
                  "Bad executable (or shared library)",
                  "Bad CPU type in executable",
                  "Shared library version mismatch",
                  "Malformed Mach-o file",
                  "Operation canceled",
                  "Identifier removed",
                  "No message of desired type",
                  "Illegal byte sequence",
                  "Attribute not found",
                  "Bad message",
                  "EMULTIHOP (Reserved)",
                  "No message available on STREAM",
                  "ENOLINK (Reserved)",
                  "No STREAM resources",
                  "Not a STREAM",
                  "Protocol error",
                  "STREAM ioctl timeout",
                  "Operation not supported on socket",
                  "Policy not found",
                  "State not recoverable",
                  "Previous owner died",
                  "Interface output queue is full"};

#endif
#define ERROR_SIZE 512

char errors_message[ERROR_SIZE] = {0};

s21_size_t s21_strlen(const char *string) {
  s21_size_t count = 0;
  const char *pr = string;
  for (; *pr != '\0'; pr++) {
    count++;
  }
  return count;
}

char *s21_strcpy(
    char *string,
    const char *source) {  // string - куда копируем, source - что копируем
  char *tmp = string;
  while (*source || *tmp) {
    *tmp = *source;
    if (*tmp != '\0' || *source != '\0') {
      tmp++;
      source++;
    }
  }
  return string;
}

char *s21_strncpy(char *string, const char *source,
                  s21_size_t num) {  // string - куда копируем, source - что
                                     // копируем, num - сколько копируем
  char *tmp = string;
  while (((*string != '\0') || (*source != '\0')) && num) {
    *string++ = *source++;
    num--;
  }
  return tmp;
}

char *s21_strcat(
    char *string,
    const char *source) {  // string - куда добавляем, source - что добавляем
  char *pr = string;
  for (; *pr != '\0'; pr++)
    ;
  while (*source != '\0') {
    *pr++ = *source++;
  }
  *pr = 0;

  return string;
}

void *s21_memchr(const void *string, int ch, s21_size_t n) {
  unsigned char *pr = (unsigned char *)string;
  while (n--) {
    if (*pr == (unsigned char)ch) {
      return (void *)pr;
    } else {
      pr++;
    }
  }
  return 0;
}

int s21_memcmp(const void *string1, const void *string2, s21_size_t n) {
  const unsigned char *pr1 = string1, *pr2 = string2;

  while (n--) {
    if (*pr1 != *pr2) {
      return *pr1 - *pr2;
    } else {
      pr1++;
      pr2++;
    }
  }
  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *pr1 = (unsigned char *)dest;
  const unsigned char *pr2 = (const unsigned char *)src;
  while (n--) {
    *pr1++ = *pr2++;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *pr = str;
  while (n--) {
    *pr++ = (unsigned char)c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *pr = dest;
  for (; *pr != '\0'; pr++)
    ;
  while (n--) {
    if (*src == '\0') {
      break;
    }
    *pr++ = *src++;
  }
  *pr = 0;
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *pr = (char *)str;
  if (*pr == '\0' && c == 0) {
    return (pr);
  }
  for (; *pr != '\0'; pr++) {
    if (*pr == c) {
      return (char *)pr;
    }
  }
  if (*pr == '\0' && c == 0) {
    return (pr);
  }
  return 0;
}

int s21_strcmp(const char *str1, const char *str2) {
  const unsigned char *pr1 = (const unsigned char *)str1;
  const unsigned char *pr2 = (const unsigned char *)str2;
  while (1) {
    if (*pr1 - *pr2 != 0) {
      return ((int)*pr1 - (int)*pr2);
    }
    if (*pr1 == '\0' || *pr2 == '\0') {
      break;
    } else {
      pr1++;
      pr2++;
    }
  }
  return 0;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const unsigned char *pr1 = (const unsigned char *)str1;
  const unsigned char *pr2 = (const unsigned char *)str2;
  for (; n != 0; pr1++, pr2++) {
    if (*pr1 - *pr2 != 0) {
      return ((int)*pr1 - (int)*pr2);
    }
    if (*pr1 == '\0' || *pr2 == '\0') {
      break;
    }
    n--;
  }
  return 0;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      return (res);
    } else {
      str1++, res++;
    }
  }
  return res;
}

char *s21_strpbrk(
    const char *str1,
    const char *str2) {  // Находит первый символ в строке str1, который
                         // соответствует любому символу, указанному в str2. |
  const char *pr1 = str1;
  for (; *pr1 != '\0'; pr1++) {
    if (s21_strchr(str2, *pr1)) {
      return (char *)pr1;
    }
  }
  return 0;
}

char *s21_strrchr(const char *str, int c) {
  const char *pr = '\0';
  const char *pr1 = str;
  for (; *pr1 != '\0'; pr1++) {
    if (*pr1 == (char)c) {
      pr = pr1;
    }
  }
  if (*pr1 == '\0' && c == 0) {
    pr = pr1;
  }
  return (char *)pr;
}

s21_size_t s21_strspn(
    const char *str1,
    const char *str2) {  // Вычисляет длину начального сегмента str1, который
                         // полностью состоит из символов str2. |
  s21_size_t res = 0;
  char *pr1 = (char *)str1;
  char *pr2 = (char *)str2;
  for (; *pr1 != '\0' && s21_strchr(pr2, *pr1++);) {
    res++;
  }
  return res;
}

char *s21_strstr(
    const char *haystack,
    const char *needle) {  //| Находит первое вхождение всей строки needle (не
                           // включая завершающий нулевой символ), которая
                           // появляется в строке haystack. |
  s21_size_t len = s21_strlen(needle);
  const char *pr1 = haystack;
  if (*pr1 == '\0') {
    if (!s21_memcmp(pr1, needle, len)) {
      return (char *)pr1;
    }
  }
  for (; *pr1 != '\0'; pr1++) {
    if (!s21_memcmp(pr1, needle, len)) {
      return (char *)pr1;
    }
  }
  return 0;
}
char *s21_strtok(char *str, const char *delim) {
  static char *pr = 0;
  if (str != S21_NULL)
    pr = str;
  else if (pr == 0) {
    return 0;
  }

  str = pr + s21_strspn(pr, delim);
  pr = str + s21_strcspn(str, delim);
  if (pr == str) {
    return pr = 0;
  }
  if (*pr > 0) {
    *pr = 0;
    pr++;
  } else {
    pr = 0;
  }
  return str;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *prd = dest;
  const unsigned char *prs = src;
  if (prs < prd)
    for (prd += n, prs += n; n--;) *(--prd) = *(--prs);
  else
    while (n--) *prd++ = *prs++;
  return dest;
}

char *s21_strerror(int errnum) {
  if (errnum >= 0 && errnum < SUM_ERRORS) {
    return (errors[errnum]);
  } else {
    s21_sprintf(errors_message, OUT_ERROR, errnum);
    return (errors_message);
  }
}
