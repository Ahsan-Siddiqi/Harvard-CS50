SELECT title FROM movies WHERE year = 2010 AND id IN (SELECT movie_id FROM ratings ORDER BY rating DESC);
