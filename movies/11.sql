SELECT title FROM movies WHERE id IN (SELECT movie_id FROM ratings ORDER BY rating LIMIT 5)
