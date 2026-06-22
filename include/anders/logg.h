#ifndef ANDERS_LOGG_H
#define ANDERS_LOGG_H

enum {LOGG_ERROR, LOGG_SUCCESS, LOGG_INFO};
enum {LOGG_COLOR};

void logg(int type, const char *message);
void init_logg(int i);

int logg_error(const char *, ...);
#define logge(...) logg_error(__VA_ARGS__, NULL)

static inline void loggi(const char *message)
{
	logg(LOGG_INFO, message);
}

static inline void loggs(const char *message)
{
	logg(LOGG_SUCCESS, message);
}

#endif // ANDERS_LOGG_H
